# ft\_server

Write a Dockerfile for system management.
Dockerfile is script to automate your tasks.  
the "docker" technology and use it to install a complete web server.  
This server will run three services, for instance, Wordpress, phpMyAdmin, and a SQL database.

## Usage

1. Create an image
```
docker build -t [image name] .
```

2. Confirm an image
```
docker images
```

3. Create a contena from an image
```
docker run -d -p 8080:80 -p 443:443 --name [contena name] [image name]
```

4. Confirm a contena
```
docker ps
```

5. Get inside the container with bash
```
docker exec -it [contena name] bin/bash
```

6. Stop a contena
```
docker stop [contena ID]
```

7. Remove a contena
```
docker rm [contena ID]
```

8. Remove a image
```
docker rmi [image ID]
```

## Note

You can use $() in the docker command like an environment variable. For instance,  

1. When you want to remove all images
```
docker rmi $(docker images -q)
```

2. When you want to remove all contenas
```
docker rm $(docker rm -aq)
```

* -q is option that shows only ID of container/image.
* -a is option that shows all(moving container/image, stop container/image).

