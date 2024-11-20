# minitalk

**minitalk** is a 42 project that involves creating a simple communication program between a server and a client using UNIX signals (`SIGUSR1` and `SIGUSR2`). The project introduces inter-process communication (IPC) and reinforces understanding of signals and asynchronous communication in C.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Compiling the Project](#compiling-the-project)
- [How to Use](#how-to-use)

## Introduction

The **minitalk** project consists of two programs: 

- **Server**: Waits for signals from a client and reconstructs the message sent.
- **Client**: Sends a message to the server using signals (`SIGUSR1` and `SIGUSR2`).

This project demonstrates how to manage asynchronous communication, encode and decode messages using signals, and handle edge cases like unexpected signal interruptions.

## Features

- Server program displays messages received from clients.
- Client program sends messages to the server using signals.
- Handles long messages by transmitting them character by character.
- Robust against invalid input and unexpected signal interruptions.


### Compile the Project

To compile the **minitalk** programs, use the `Makefile` provided:

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/abboudje/minitalk.git
   cd minitalk

2. Compile the server and client:
   ```bash
   make


## How to Use

1. Running the Server
	Start the server first. The server prints its process ID (PID) when run:
	```bash
	./server

- You will see output like this:
	```bash
	Server PID: 12345
	
2. Sending Messages with the Client
	```bash
	./client 12345 "Hello, Minitalk!"
- The server will display the message:
	```bash
	Received message: Hello, Minitalk!

