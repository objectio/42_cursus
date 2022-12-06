all:
	@sudo mkdir -p ~/data
	@sudo mkdir -p ~/data/mysql ~/data/wordpress 
	@sudo docker compose -f ./srcs/docker-compose.yml up -d --build --remove-orphans

down:
	@sudo docker compose -f ./srcs/docker-compose.yml down

re:
	@sudo docker compose -f ./srcs/docker-compose.yml up -d --build

clean:
	@sudo docker compose -f ./srcs/docker-compose.yml down -v --rmi all

fclean: clean
	sudo rm -rf $(HOME)/data
	sudo docker network prune -f
	sudo docker volume prune -f 
	sudo docker image prune -a -f

.PHONY: all re down clean fclean
