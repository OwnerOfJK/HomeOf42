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
	cd src && docker image rm -f $(docker image ls -aq)

delete_containers:
	cd src && docker container rm -f $(docker container ls -aq)

delete_volumes:
	cd src && docker volume rm -f $(docker volume ls -q)

delete_networks:
	cd src && docker network rm $(docker network ls -q | grep -v 'bridge\|host\|none')

prepare_eval:
	make clean
	make delete_images
	make delete_containers
	make delete_volumes
	make delete_networks