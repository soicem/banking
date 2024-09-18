FROM ubuntu:latest

# Install necessary packages
RUN apt-get update && \
    apt-get install -y g++ cmake git libgtest-dev libgmock-dev

# Set up a working directory
WORKDIR /app

# Copy the source code
COPY . /app

# Build the tests using CMake
RUN g++ -std=c++14 atm_test.cpp -lgtest -lgtest_main -lgmock -pthread -o atm_test

# Run the tests
CMD ["./atm_test"]
