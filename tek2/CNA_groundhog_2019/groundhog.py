#!/usr/bin/env python3
import sys
from math import sqrt

queue = []
weirdestValues = []
numberSwitch = 0


def isNumber(value):
    try:
        float(value)
        return True
    except ValueError:
        return False


def exitError(msg):
    print(f'ERROR: {msg}', file=sys.stderr)
    sys.exit(84)

def displayUsage(returnValue):
    print("SYNOPSIS\n\t./groundhog period")
    print("DESCRIPTION\n\tperiod the number of days defining a period\n")
    sys.exit(returnValue)


def temperatureIncreaseAverage(period):
    if (len(queue) <= period):
        return "nan"
    try:
        tmp = list(map(lambda x, y: max(0, x - y), queue[-period:],
                       queue[-(period + 1):-1]))
        avg_inc = sum(tmp) / period
        return f'{avg_inc:.2f}'
    except (ValueError, FloatingPointError, ZeroDivisionError):
        return "nan"


def relativeTemperature(period):
    if (len(queue) <= period):
        return "nan"
    try:
        return round((queue[-1] / queue[-(1 + period)] - 1) * 100)
    except (ValueError, FloatingPointError, ZeroDivisionError):
        return "nan"


def standardDerivation(period):
    if (len(queue) >= period):
        try:
            avg = sum(queue[-period:]) / period
            tmp = map(lambda x: (x - avg) ** 2, queue[-period:])
            s = sqrt(sum(tmp) / period)
            return f'{s:.2f}'
        except (ValueError, FloatingPointError, ZeroDivisionError):
            return "nan"
    return "nan"


def getDeviation(period):
    if (len(queue) < period):
        return None
    try:
        avg = sum(queue[-period:]) / period
        dev = sqrt(sum(map(lambda x:(x - avg)**2, queue[-period:])) / period)
        return f'{dev:.2f}'
    except (ValueError, FloatingPointError, ZeroDivisionError):
        return None


def getNewAverage(period):
    if (len(queue) < period):
        return None
    try:
        return sum(queue[-period:]) / period
    except (ValueError, FloatingPointError, ZeroDivisionError):
        return None


def process(period, last):
    global weirdestValues, queue
    averageList = []
    deviationList = []
    while(True):
        try:
            newVal = input()
            if not isNumber(newVal):
                if newVal == "STOP":
                    displayExitMessage(period)
                else:
                    exitError("bad input given. Expeted temperature (float) got string.")
            else:
                newVal = float(newVal)
                queue.append(newVal)
                g = temperatureIncreaseAverage(period)
                r = relativeTemperature(period)
                s = standardDerivation(period)
                display(g, r, s, period, last)
                last = [g, r, s]
                deviationList.append(getDeviation(period))
                deviationList = list(filter(None, deviationList))
                averageList.append(getNewAverage(period))
                try:
                    minValue = averageList[-1] - 2 * float(deviationList[-1])
                    maxValue = averageList[-1] + 2 * float(deviationList[-1])
                    weirdestValues.append((queue[-1] - minValue) / (maxValue - minValue))
                except (IndexError, ZeroDivisionError):
                    continue
        except (StopIteration, EOFError):
            exitError("EOF reached before STOP cmd")
    return 0


def display(g, r, s, period, last):
    global numberSwitch
    print(f'g={g}', end='\t')
    print(f'r={r}%', end='\t')
    print(f's={s}', end='')
    if not isinstance(last[1], str) and not isinstance(r, str):
        if (last[1] < 0 and r > 0) or (last[1] > 0 and r < 0):
            numberSwitch += 1
            print("\ta switch occurs")
        else:
            print('')
    else:
        print('')
    return 0


def displayExitMessage(period):
    global numberSwitch, queue, weirdestValues
    if len(queue) < period:
        sys.exit(84)
    print(f"Global tendency switched {numberSwitch} times")
    weirdestValues = list(map(lambda x : abs(x - .5), weirdestValues))
    final = (sorted(weirdestValues))[-5:]
    final = list(map(lambda x : queue[weirdestValues.index(x) + period - 1], final))
    if (len(final) >= 5):
        print(f"5 weirdest values are {final[::-1]}")
    else:
        exitError("Not enough weridest values to display")
    sys.exit(0)


def main():
    try:
        if len(sys.argv) != 2:
            displayUsage(84)
        elif "-h" in sys.argv or "--help" in sys.argv:
            displayUsage(0)
        elif int(sys.argv[1]) < 1:
            displayUsage(84)
        else:
            process(int(sys.argv[1]), [0, 0, 0])
            sys.exit(0)
    except ValueError:
        displayUsage(84)


main()