# Build stage
FROM gcc:latest as build
WORKDIR /build

ENV BUILD_TYPE=Debug

# Install all packages
RUN apt-get update && \
    apt-get install -y cmake

ADD ./src /app/src
ADD ./CMakeLists.txt /app

WORKDIR /app/build
# Build binaries
RUN cmake .. && \
    cmake --build .

# Run stage
FROM ubuntu:20.04

# Add user
RUN groupadd -r sample && useradd -r -g sample sample
USER sample

WORKDIR /app

COPY --from=build /app/build/DefaultCppProgram .
ENTRYPOINT ["./DefaultCppProgram"]