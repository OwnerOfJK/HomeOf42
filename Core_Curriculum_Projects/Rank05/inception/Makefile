.PHONY: build up down delete_containers delete_images delete_volumes delete_networks clean setup prepare_eval

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

delete_images:
    cd src && if [ "$(docker image ls -aq)" ]; then docker image rm -f $(docker image ls -aq); else echo "No images to delete."; fi

delete_containers:
    cd src && if [ "$(docker container ls -aq)" ]; then docker container rm -f $(docker container ls -aq); else echo "No containers to delete."; fi

delete_volumes:
    cd src && if [ "$(docker volume ls -q)" ]; then docker volume rm -f $(docker volume ls -q); else echo "No volumes to delete."; fi

delete_networks:
    cd src && if [ "$(docker network ls -q)" ]; then docker network rm $(docker network ls -q); else echo "No custom networks to delete."; fi

prepare_eval:
    make clean
    make delete_images
    make delete_containers
    make delete_volumes
    make delete_networks