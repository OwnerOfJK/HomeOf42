FROM debian:latest

RUN apt update && apt upgrade && apt install -y nginx

COPY default /etc/nginx/sites-available/default
# Here we overwrite the default configuration file with our own configuration file.

CMD ["nginx", "-g", "daemon off;"]
# daemon off: controls whether Nginx runs as a daemon (background process) or stays in the foreground.