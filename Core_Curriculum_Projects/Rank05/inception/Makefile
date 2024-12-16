.PHONY: build up down clean setup

setup:
    @if ! grep -q "jkaller.42.fr" /etc/hosts; then \
        echo "Adding jkaller.42.fr to /etc/hosts..."; \
        sudo sh -c 'echo "127.0.0.1 jkaller.42.fr" >> /etc/hosts'; \
    fi

clean:
    rm -rf /home/jkaller/data/db/*
    rm -rf /home/jkaller/data/web/*

build: setup
    cd src && docker compose up --build

up:
    cd src && docker compose up

down:
    cd src && docker compose down