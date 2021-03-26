#!/bin/env python3

import asyncio
from asyncio import subprocess as sp
import os


class BrainException(Exception):
    pass


async def create_process(filepath):
    process = await sp.create_subprocess_exec(
        filepath, stdin=sp.PIPE, stdout=sp.PIPE, stderr=sp.PIPE)

    return process

    # @staticmethod
    # def _get_event_loop():
    #     if os.name == "nt":
    #         loop = asyncio.ProactorEventLoop()
    #         asyncio.set_event_loop(loop)
    #     else:
    #         loop = asyncio.get_event_loop()

    #     return loop

    # def _init_process(self, filepath):
    #     self._process = sp.create_subprocess_exec(
    #         filepath, stdin=sp.PIPE, stdout=sp.PIPE, stderr=sp.PIPE)

    #     loop = self._get_event_loop()
    #     loop.run_until_complete(self._process)

    @staticmethod
    async def create_process(filepath):
        process = await sp.create_subprocess_exec(
            filepath, stdin=sp.PIPE, stdout=sp.PIPE, stderr=sp.PIPE)

        return process

    def __del__(self):
        self._process.kill()
        asyncio.run(self._process.wait())

    async def _send(self, msg):
        b = bytes(msg + '\n', "utf-8")

        self._process.stdin.write(b)
        await self._process.stdin.drain()

    async def _readline(self):
        return await self._process.stdout.readline()

    def send_start_cmd(self, size):
        asyncio.run(self._send(f"START {size}"))

        line = asyncio.run(self._readline())
        print(line)
        return line

    def send_turn_cmd(self, x, y):
        pass

    def send_begin_cmd(self):
        pass

    def send_board_cmd(self):
        pass

    def send_info_cmd(self):
        pass

    def send_end_cmd(self):
        pass

    def send_about_cmd(self):
        pass

    def send_restart_cmd(self):
        pass
