all:
	@docker compose -f ./srcs/docker-compose.yml up -d --build --remove-orphans

down:
	@docker compose -f ./srcs/docker-compose.yml down

re:
	@docker compose -f ./srcs/docker-compose.yml up -d --build

clean:
	@docker compose -f ./srcs/docker-compose.yml down --rmi all

.PHONY: all re down clean
