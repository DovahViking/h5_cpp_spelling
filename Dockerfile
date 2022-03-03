FROM ubuntu:latest

RUN apt update
RUN apt install g++ -y

EXPOSE 8000

COPY *.cpp /app/

RUN g++ /app/Server_Side.cpp -o /app/Server_Side

ENTRYPOINT ["/app/Server_Side"]

# docker build -t h5_cpp_image .
# docker run --name h5_cpp_container --rm h5_cpp_image