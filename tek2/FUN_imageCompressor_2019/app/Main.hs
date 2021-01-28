--
-- EPITECH PROJECT, 2019
-- FUN_imageCompressor_2019
-- File description:
-- Main
--

module Main where

import System.Environment
import System.Exit
import Control.Exception(IOException, catch)
import System.IO(IOMode(ReadMode), withFile, hGetContents, hPutStrLn, stderr)
import Data.List
import Data.Array ((!))
import Text.Read
import Text.Printf

type POINT = (Int, Int)

type COLORMEAN = (Float, Float, Float)

type COLOR = (Int, Int, Int)

type PIXEL = (POINT, COLOR)

type CLUSTER = (COLORMEAN, [PIXEL])

-- Starting programm
getValueForKmean :: [String] -> Int -> IO()
getValueForKmean args len
    | len /= 3 = hPutStrLn stderr "ERROR: 3 args excpected. n e and IN" >> exitWith(ExitFailure (84))
    | isInt ((!!) args 0) == False = hPutStrLn stderr "ERROR: n must be an int" >> exitWith (ExitFailure (84))
    | isFloat ((!!) args 1) == False = hPutStrLn stderr "ERROR: n must be a float" >> exitWith (ExitFailure (84))
    | otherwise = readFileParameter (read ((!!) args 0)::Int) (read ((!!) args 1)::Float) ((!!) args 2)

-- Tools
isInt :: String -> Bool
isInt strInt = case (readMaybe strInt::Maybe Int) of
                Just i  -> True
                Nothing -> False

isFloat :: String -> Bool
isFloat strFloat = case (readMaybe strFloat::Maybe Float) of
                Just i  -> True
                Nothing -> False

-- Display
replaceValue :: Int -> any -> [any] -> [any]
replaceValue pos newVal list = take pos list ++ newVal : drop (pos+1) list

printPixel :: PIXEL -> IO ()
printPixel ((x,y), (r,g,b)) = printf "(%d,%d) (%d,%d,%d)\n" x y r g b

printCluster :: CLUSTER -> IO()
printCluster (mean, pixels) = do
                printf "--\n"
                print mean
                printf "-\n"
                mapM_ (printPixel) pixels

printClusters :: [CLUSTER] -> IO()
printClusters clusters = mapM_ (printCluster) clusters

-- File Manager
readFileParameter :: Int -> Float -> String -> IO ()
readFileParameter n e file = do
        catch (withFile file ReadMode (\handle -> do  
                contents <- hGetContents handle
                let pixels = (createPixelArray) (lines contents) [] 0
                let addToLimit = round (((fromIntegral (length pixels)) / (fromIntegral n)) + 0.5)
                let firstClusters = createClusterArray pixels [((0,0,0), [])] 0 0 addToLimit addToLimit
                let newCluster = (sortCluster (convergenceClusters firstClusters pixels 0 (replicate (length firstClusters) ((0,0,0), []))) pixels 0)
                untilConvergence e firstClusters newCluster 0 pixels
                ))
            (\exc -> print (exc :: IOException) >> exitWith(ExitFailure 84))

-- Kmean

untilConvergence :: Float -> [CLUSTER] -> [CLUSTER] -> Int -> [PIXEL] -> IO()
untilConvergence e oldClusters newClusters indexCluster pixels
                | indexCluster == (length newClusters) = printClusters newClusters
                | (getDistanceCluster ((!!) oldClusters indexCluster) ((!!) newClusters indexCluster)) < e =
                    untilConvergence e oldClusters newClusters (indexCluster + 1) pixels
                | otherwise = untilConvergence e newClusters (sortCluster renewedClusters pixels 0) 0 pixels
                    where renewedClusters = convergenceClusters newClusters pixels 0 (replicate (length newClusters) ((0,0,0), []))

convergenceClusters :: [CLUSTER] -> [PIXEL] -> Int -> [CLUSTER] -> [CLUSTER]
convergenceClusters clusters pixels indexPixel newCluster
                | indexPixel == (length pixels) = newCluster
                | otherwise = convergenceClusters clusters pixels (indexPixel + 1) (addPixelCluster ((!!) newCluster newIndex) newCluster newIndex pixels indexPixel)
                            where newIndex = getLessDistance ((!!) pixels indexPixel) clusters 0 0 (getDistance ((!!) clusters 0) ((!!) pixels indexPixel))

createPixelArray :: [String] -> [PIXEL] -> Int -> [PIXEL]
createPixelArray lines pixels index 
                | (length lines) == index = pixels
                | otherwise = createPixelArray lines (pixels ++ [createPixel ((!!) lines index)]) (index + 1)

createPixel :: String -> PIXEL
createPixel line = ((read ((!!) wordsArray 0) :: POINT), read ((!!) wordsArray 1) :: COLOR)
                    where wordsArray = words line

createClusterArray :: [PIXEL] -> [CLUSTER] -> Int -> Int -> Int -> Int -> [CLUSTER]
createClusterArray pixels clusters index indexCluster limitCluster addToLimit
                | (length pixels) == index = (modifCluster ((!!) clusters indexCluster) clusters indexCluster)
                | index == limitCluster = createClusterArray pixels (newClusters ++ [((0,0,0), [])]) index (indexCluster + 1) (limitCluster + addToLimit) addToLimit
                | otherwise = createClusterArray pixels newClusters2 (index + 1) indexCluster limitCluster addToLimit
                where   newClusters2 = addPixelCluster ((!!) clusters indexCluster) clusters indexCluster pixels index
                        newClusters = (modifCluster ((!!) clusters indexCluster) clusters indexCluster)

addPixelCluster :: CLUSTER -> [CLUSTER] -> Int -> [PIXEL] -> Int -> [CLUSTER]
addPixelCluster (coolormean, pixelsCluster) clusters indexCluster pixels indexPixel = replaceValue indexCluster newCluster clusters
                where   newPixels = pixelsCluster ++ [(!!) pixels indexPixel]
                        newCluster = setMeanCluster (coolormean, newPixels) ((!!) pixels indexPixel) 

setMeanCluster :: CLUSTER -> PIXEL -> CLUSTER 
setMeanCluster  ((r_mean, g_mean, b_mean), pixels) (p, (r, g, b)) = ((r_mean + (fromIntegral r), g_mean + (fromIntegral g), b_mean + (fromIntegral b)), pixels)

modifCluster :: CLUSTER -> [CLUSTER] -> Int -> [CLUSTER]
modifCluster    ((r_mean, g_mean, b_mean), pixels) clusters indexCluster = replaceValue indexCluster (((r_mean / (fromIntegral (length pixels))),(g_mean / (fromIntegral (length pixels))),(b_mean / (fromIntegral (length pixels)))), pixels) clusters

sortCluster :: [CLUSTER] -> [PIXEL] -> Int -> [CLUSTER]
sortCluster  clusters pixels indexCluster
                | indexCluster == (length clusters) = clusters
                | otherwise = sortCluster newCluster pixels (indexCluster + 1)
                        where newCluster = modifCluster ((!!) clusters indexCluster) clusters indexCluster


getLessDistance :: PIXEL -> [CLUSTER] -> Int -> Int -> Float -> Int
getLessDistance pixel clusters indexCluster lastIndexLessValue distance
                | (length clusters) == indexCluster = lastIndexLessValue
                | (getDistance (clusters !! indexCluster) pixel) < distance = getLessDistance pixel clusters (indexCluster + 1) indexCluster (getDistance ((!!) clusters indexCluster) pixel)
                | otherwise = getLessDistance pixel clusters (indexCluster + 1) lastIndexLessValue distance

getDistanceCluster :: CLUSTER -> CLUSTER -> Float
getDistanceCluster ((r_mean, g_mean, b_mean),pixels) ((r,g,b), pixels2) = sqrt ((r_mean - r)^2 + (g_mean - g)^2 + (b_mean - b)^2)

getDistance :: CLUSTER -> PIXEL -> Float
getDistance ((r_mean, g_mean, b_mean),pixels) ((x,y),(r,g,b)) = sqrt ((r_mean - (fromIntegral r))^2 + (g_mean - (fromIntegral g))^2 + (b_mean - (fromIntegral b))^2)

main :: IO()
main = do
    args <- getArgs
    getValueForKmean args (length args)