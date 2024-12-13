FROM alpine:latest
COPY log_file.txt .
ENV LOG_INTERVAL=5
ENTRYPOINT ["sh", "-c"]
CMD ["while true; do echo 'Reading logs:' && cat log_file.txt; sleep $LOG_INTERVAL; done"]