# Use an official Ubuntu as a base image
FROM ubuntu:latest

# Install build essentials and tools for C/C++ development
RUN apt-get update && apt-get install -y \
    build-essential \
    gdb \
    cmake \
    clang \
    valgrind \
    git \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory inside the container
WORKDIR /app

# Copy your project files to the container
COPY . /app

# Set up any necessary environment variables
ENV CC=gcc
ENV CXX=g++

# Compile the project (optional if not using an external build system)
CMD ["make"]
