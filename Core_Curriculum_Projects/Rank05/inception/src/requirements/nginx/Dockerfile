FROM debian:bullseye

RUN apt update && apt upgrade && apt install -y nginx openssl

# Generate SSL certificates
RUN mkdir -p /etc/nginx/ssl && \
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/nginx.key \
    -out /etc/nginx/ssl/nginx.crt \
    -subj "/C=DE/ST=Berlin/L=Berlin/O=42/OU=42/CN=jkaller.42.fr"

COPY ./config/default /etc/nginx/sites-available/default
# Here we overwrite the default configuration file with our own configuration file.

CMD ["nginx", "-g", "daemon off;"]
# daemon off: controls whether Nginx runs as a daemon (background process) or stays in the foreground.