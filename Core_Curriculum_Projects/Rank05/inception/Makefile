.PHONY: build up down delete_containers delete_images delete_all_running clean setup

setup:
	@if ! grep -q "jkaller.42.fr" /etc/hosts; then \
		echo "Adding jkaller.42.fr to /etc/hosts..."; \
		sudo sh -c 'echo "127.0.0.1 jkaller.42.fr" >> /etc/hosts'; \
	fi

clean:
	rm -rf src/db/*
	rm -rf src/web/*

build: setup
	cd src && docker compose up --build

up:
	cd src && docker compose up

down:
	cd src && docker compose down

delete_images:
	cd src && docker image prune -a

delete_containers:
	cd src && docker container prune

delete_all_running:
	cd src && docker rm -f mariadb wp-php server-nginx
