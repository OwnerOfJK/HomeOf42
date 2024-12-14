.PHONY: build up down delete

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
