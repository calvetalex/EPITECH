#!/bin/env python3

import asyncio
import asyncio.subprocess as asp


async def get_output(process, input):
    process.stdin.write(input)
    await process.stdin.drain()  # flush input buffer

    out = await process.stdout.readline()  # program is stuck here

    return out


async def create_process(cmd):
    process = await asp.create_subprocess_exec(
        cmd, stdin=asp.PIPE, stdout=asp.PIPE, stderr=asp.PIPE)
    return process


async def run():
    process = await create_process("./test.py")

    out = await get_output(process, b"input #1\n")
    print(out)
    out = await get_output(process, b"input #2\n")
    print(out)
    out = await get_output(process, b"input #3\n")
    print(out)
    out = await get_output(process, b"input #4\n")
    print(out)

    process.terminate()
    await process.wait()


async def main():
    await asyncio.gather(run())

asyncio.run(main())
