FROM alpine:latest
COPY test_file.txt .
ENV GREETING="Hello from Docker!"
ENTRYPOINT ["sh", "-c"]
CMD ["echo $GREETING && cat test_file.txt"]