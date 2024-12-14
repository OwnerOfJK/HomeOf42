.PHONY: build up down delete_containers delete_images delete_all_running

build:
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
