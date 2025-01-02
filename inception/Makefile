COMPOSE_FILE = srcs/requirements/docker-compose.yml
DOCKER_COMPOSE = docker compose

help:
	@echo "Available targets:"
	@echo "  up      	- Start services and always build images"
	@echo "  down     	- Stop services and remove containers"
	@echo "  downv     	- Stop services and remove containers and volumes"
	@echo "  restart  	- Restart services"
	@echo "  ps       	- List running containers"
	@echo "  clean    	- Remove stopped containers, networks and volumes"

create_dirs:
	@echo "Creating necessary directories if they don't exist"
	@mkdir -p /home/pclaus/data/wordpress
	@mkdir -p /home/pclaus/data/mariadb

up: create_dirs
	$(DOCKER_COMPOSE) -f $(COMPOSE_FILE) up --build

down:
	$(DOCKER_COMPOSE) -f $(COMPOSE_FILE) down

downv:
	$(DOCKER_COMPOSE) -f $(COMPOSE_FILE) down -v

restart: down up

ps:
	$(DOCKER_COMPOSE) -f $(COMPOSE_FILE) ps

clean:
	$(DOCKER_COMPOSE) -f $(COMPOSE_FILE) down --volumes --remove-orphans

.PHONY: help up down downv restart ps clean
