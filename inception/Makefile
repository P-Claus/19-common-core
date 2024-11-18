COMPOSE_FILE = srcs/requirements/docker-compose.yml
DOCKER_COMPOSE = docker compose

.PHONY: help
help:
	@echo "Available targets:"
	@echo "  up      	- Start services and always build images"
	@echo "  down     	- Stop services and remove containers"
	@echo "  downv     	- Stop services and remove containers and volumes"
	@echo "  restart  	- Restart services"
	@echo "  ps       	- List running containers"
	@echo "  clean    	- Remove stopped containers, networks and volumes"

.PHOMY: up
up:
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
