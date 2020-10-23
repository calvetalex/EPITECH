--
-- EPITECH PROJECT, 2020
-- wolfram
-- File description:
-- CA generation
--

import System.Environment
import System.Exit
import System.IO (hPutStrLn, stderr)
import Data.List (findIndex)
import Data.Array (listArray, (!), bounds, elems)
import Text.Read

-- a cell can be in one of two states
type Cell = Bool     -- Cell can have two state : 0 or 1
type Config = [Cell] -- config will be the map, an array of Cell

-- LocalRule: (a cell) -> (left neighbor) -> (right nedn't match expected type ‘IO Flags’ with actual type ‘Flags’ighbor) -> (new cell)
type LocalRule = Cell -> Cell -> Cell -> Cell -- default proto

-- Flags structure to manage argv
data Flags = Flags { ruleGiven :: Int, windowGiven :: Int, linesGiven :: Int, startGiven :: Int, moveGiven :: Int} deriving (Show) -- deriving (Show) allowed us to print struct

-- getters of flags
getFlags :: [String] -> Flags
getFlags args = Flags r w l s m                                               -- define rule to get flags
    where
        r = case findIndex (\elem -> elem == "--rule") (args) of                -- check if --rule is in list
            Nothing -> -1                                                       -- if not, don't set option
            Just n -> case length args > (n+1) of                                   -- if founded we check that we have a number following this option
                True -> case readMaybe ((!!) args (n+1))::Maybe Int of              -- checking next argv
                      Just a -> a                                                   -- if nb founded, set option to this
                      Nothing -> -1                                                 -- else error set
                False -> -1                                                         -- if nb not found error is set
        w = case findIndex (\elem -> elem == "--window") (args) of               -- do the same thing as for --rule option for --window, --lines, --start, --move
            Nothing -> 80
            Just n -> case length args > (n+1) of
                True -> case readMaybe ((!!) args (n+1))::Maybe Int of
                      Just a -> a
                      Nothing -> -1
                False -> -1
        l = case findIndex (\elem -> elem == "--lines") (args)of
            Nothing -> (maxBound)::Int
            Just n -> case length args > (n+1) of
                True -> case readMaybe ((!!) args (n+1))::Maybe Int of
                      Just a -> a
                      Nothing -> -1
                False -> -1
        s = case findIndex (\elem -> elem == "--start") (args)of
            Nothing -> 0
            Just n -> case length args > (n+1) of
                True -> case readMaybe ((!!) args (n+1))::Maybe Int of
                      Just a -> a
                      Nothing -> -1
                False -> -1
        m = case findIndex (\elem -> elem == "--move") (args) of
            Nothing -> 0
            Just n -> case length args > (n+1) of
                True -> case readMaybe ((!!) args (n+1))::Maybe Int of
                      Just a -> a
                      Nothing -> -1
                False -> -1

-- some popular initial configurations
center::Int -> Config
center width
    | width `mod` 2 == 1 = (take (floor $ (((fromIntegral width) - 1) / 2) + 1) $ repeat False) ++ [True] ++ (take (floor $ (fromIntegral width) / 2) $ repeat False) -- print configuration
    | otherwise = (take (floor $ (((fromIntegral width) - 1) / 2) + 1) $ repeat False) ++ [True] ++ (take ((floor $ (fromIntegral width) / 2) - 1) $ repeat False)

-- global rule: update the entire configuration
-- this is done by synchronously applying the local rule to each cell
global::LocalRule -> Config -> Config
global rule config = map (local config) [0..hi]                 -- checking elems from our config
    where
        local config index =
          let len = length config                               -- setting len to our config len
              cell = (!!) config index                          -- get current cell
              right = (!!) config $ mod (index - 1) len              -- get neighborhood cells
              left = (!!) config $ mod (index + 1) len
           in rule cell left right
        hi = length config - 1                                  -- go to the next cell

-- ultimate simulation wrapper for a given LocalRule, staring Config, and depth
displayCA::LocalRule -> Config -> Int -> Int -> Int -> IO ()
displayCA rule initial depth begin move = putStrLn $ (take move $ cycle " ") ++ run (global rule) initial (depth - 1)                                             -- print loop
    where
        run rule initial 0 = (map (\x -> if x then '*' else ' ') initial)                                                                                         -- rule for the first iteration
        run rule initial n = (map (\x -> if x then '*' else ' ') initial) ++ "\n" ++ (take move $ cycle " ") ++ (run rule (rule initial) (n - 1))                 -- global rule for the rest of the array

-- make a LocalRule from its Wolfram code
rule::Int -> LocalRule
rule n =
    \cell left right -> (map to_bool $ pad8 $ binary_expand n) !! (7 - cell_as_num cell left right)     -- lambda to get cell status by getting binary value of rule and getting the current cell and her neighbors
    where
        to_num False = 0
        to_num True = 1                                                                   -- set cell status
        to_bool  = not . (== 0)                                                                         -- get boolean value of cell
        cell_as_num c l r = sum $ map (\(x,y) -> 2^x * y ) $ zip [0..] $ map to_num [l, c, r]           -- get new cell value

-- Dec to bin logic, forcing binary to size 8
-- rounded log base 2 of an integer
log2::Int -> Int
log2 x = floor $ log (fromIntegral x) / log 2                   -- return binary value of integer

-- expand, e.g. 12 -> [1, 1, 0, 0]
binary_expand::Int -> [Int]
binary_expand n = bin_exp_aux n $ log2 n                        -- getting binary value of int
    where
        bin_exp_aux x d
            | d < 0 = []
            | x >= 2^d = 1 : bin_exp_aux (x - 2^d) (d - 1)
            | otherwise = 0 : bin_exp_aux x (d - 1)

-- force binary number to length 8, chopping off upper bits if needed
pad8::[Int] -> [Int]
pad8 num
    | length num <= 8 = pad ++ num
    | length num > 8  = drop len num
    where
        len = abs $ 8 - (length num)
        pad = take len $ repeat 0

-- first parsing option to check arguments
parse :: [String] -> IO ()
parse [] = usage
parse ["-h"] = usage
parse ["--help"] = usage
parse ["-v"] = version
parse ["--version"] = version
parse a = return ()

usage = do
    putStrLn "USAGE:\n\t./wolfram [-h] [-v] --rule A [--start B] [--lines C] [--window D] [--move E]\n\nDESCRIPTION:\n"
    putStrLn "\t-h        display this help"
    putStrLn "\t--rule    rule number the program will use"
    putStrLn "\t--start   generation number at which the program will start to print. Default = 0"
    putStrLn "\t--lines   number of lines to print until the programm stop. Default is infinite"
    putStrLn "\t--window  size of the window for each line to print. The first line will be in the center of the window."
    putStrLn "\t--move    lateral movement of the center of window"
    exit
version = putStrLn "version: alpha 0.0.4" >> exit
exit = exitWith ExitSuccess
exit_error = exitWith (ExitFailure 84)

flagsHandling::Flags -> IO()
flagsHandling flags = do
    case ruleGiven flags == -1 || ruleGiven flags < 0 || ruleGiven flags > 255 of
        True -> hPutStrLn stderr "Bad rule given. Please enter --rule X with X an 256 > Integer > 0" >> exit_error
        False -> return ()
    case linesGiven flags == -1 || linesGiven flags < 0 of
        True -> hPutStrLn stderr "Bad lines given. Please enter --lines X with X an Integer > 0" >> exit_error
        False -> return ()
    case windowGiven flags == -1 || windowGiven flags < 0 of
        True -> hPutStrLn stderr "Bad window given. Please enter --window X with X an Integer > 0" >> exit_error
        False -> return ()
    case moveGiven flags == -1 || moveGiven flags < 0 of
        True -> hPutStrLn stderr "Bad move given. Please enter --move X with X an Integer > 0" >> exit_error
        False -> return ()
    case startGiven flags == -1 || startGiven flags < 0 of
        True -> hPutStrLn stderr "Bad start given. Please enter --start X with X an Integer > 0" >> exit_error
        False -> return ()

main = do
    args <- getArgs
    parse args
    let flags = getFlags args
    flagsHandling flags
    displayCA (rule $ ruleGiven flags) (center $ windowGiven flags) (linesGiven flags) (startGiven flags) (moveGiven flags)
    exit