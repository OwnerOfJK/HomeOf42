## Intro into Stack

### MariaDB

MariaDB is an open-source relational database management system (RDBMS). It is designed to store and manage structured data and is backwards compatible to MySQL..

It was forked from MySQL (another DB) by its original developers after MySQL got acquired by Oracle.

SQL: A language used to query and manipulate relational databases.

### Nginx

Nginx is an open-source web server that is widely used for hosting websites, serving as a reverse proxy, and acting as a load balancer.

It is known for its high performance, scalability, and ability to handle a large number of simultaneous connections efficiently, making it ideal for modern web applications.

In this project, Nginx serves as the web server, delivering static content (e.g., HTML, CSS, JS) and forwarding dynamic PHP requests to the PHP-FPM service.

### PHP wordpress

**PHP**: PHP is a server-side scripting language used to build dynamic web applications. It processes requests, interacts with databases (like MariaDB), and generates HTML pages for users.

**WordPress**: WordPress is a popular open-source content management system (CMS) written in PHP. It simplifies the creation and management of websites, offering features such as themes, plugins, and a user-friendly interface.

In this project:

- PHP handles WordPress's backend logic and processes PHP scripts.
- WordPress serves as the CMS for building and managing the website content. It interacts with MariaDB to store and retrieve data (e.g., posts, user accounts) and uses Nginx to serve the resulting web pages.

## Config Files

In order to allow the wordpress site and the nginx server to communicate so that the server can actually server the site we need to change the config files.

### Wordpress PHP
1. The config file **relevant to us** is located at: `/etc/php/8.2/fpm/pool.d/www.conf`
    - Role: It is a PHP-FPM (FastCGI Process Manager) pool configuration file. This file configures a pool of PHP-FPM worker processes. A pool is a set of processes that handle PHP script execution for a specific application or virtual host (e.g., your WordPress site).

`docker cp wp-php:/etc/php/8.2/fpm/pool.d/www.conf ./requirements/wordpress/.`

#### Change
We need to change:

1. from `listen = /run/php/php8.2-fpm.sock` to `listen = wp-php:9000`
    - the wordpress site and nginx are in seperate containers. Containers communicate over a network, so PHP-FPM must listen on a TCP socket (wp-php:9000) rather than a Unix socket (/run/php/php8.2-fpm.sock).
    - unix sockets (i.e. `/run/php/php8.2-fpm.sock`) only works for processes running on the same server or container.

### Nginx
1. The main nginx config files is located at: `/etc/nginx/nginx.conf`
    - Role: Acts as the global configuration file for Nginx.
    - Scope: Defines global settings that apply to the entire Nginx server, including worker processes, logging, and modules.
    - Includes: References additional configuration files like conf.d/*.conf and sites-enabled/*.

`docker cp nginx:/etc/nginx/nginx.conf ./requirements/nginx/.`

2. The config file **relevant to us** is located at: `/etc/nginx/sites-available/default`
    - Role: Manages configuration for a specific virtual host or website.
    - Scope: Defines the behavior for a single site or domain (e.g., which files to serve, how requests are handled).
    - Includes: This file is linked into /etc/nginx/sites-enabled/ to activate the site.

`docker cp server-nginx:/etc/nginx/sites-available/default ./requirements/nginx/.`

#### Changes

We need to change:

1. Uncomment the following codeblock, and change `fastcgi_pass 127.0.0.1:9000;` to `fastcgi_pass wp-php:9000`

``` default
location ~ \.php$ {
		include snippets/fastcgi-php.conf;
	
		# With php-fpm (or other unix sockets):
		# fastcgi_pass unix:/run/php/php7.4-fpm.sock;
		# With php-cgi (or other tcp sockets):
		fastcgi_pass 127.0.0.1:9000;
	}
```
- Once uncommented `location ~ \.php$` matches all requests for files ending with .php.
- `fastcgi_pass wp-php:9000` specifies to nginx to what FastCGI server (PHP-FPM) PHP requests should be forwarded to.

2. add `index.php` to the following line: 	`index index.html index.htm index.nginx-debian.html;` (line 44)

### MariaDB

1. The main config file is located at: `/etc/mysql/mariadb.cnf`
    - Role: Includes directives for server behavior, logging, storage engines, networking, etc.

`docker cp mariadb:/etc/mysql/mariadb.cnf ./requirements/mariadb/.`

2. The config file **relevant to us** is located at: `/etc/mysql/mariadb.conf.d/50-server.cnf`
    - Role: This configuration file contains settings specific to the MariaDB server, defining how it operates and interacts with the system.

`docker cp mariadb:/etc/mysql/mariadb.conf.d/50-server.cnf ./requirements/mariadb/.`

#### Changes

We need to change:

1. Uncomment and change user variable (line 15), from `# user = mysql` to `user = root`.
    - MariaDB usually runs under a non-privileged system user like mysql for security reasons. This prevents the database process from making unauthorized changes or accessing sensitive files outside its scope.
2. Uncommment (line 18 and 19) `datadir = /var/lib/mysql` and `tmpdir = /tmp`
    - `datadir` Specifies the directory where MariaDB stores its data files, including database tables, indexes, and logs.
    - `tmpdir` Specifies the directory used for temporary files, such as intermediate query results or temporary tables.
3. Change bind-adddress (line 27) from `bind-address = 127.0.0.1` to `bind-address = mariadb`
    - `127.0.0.1` limits MariaDB to accept connections only from the same machine. While secure, it prevents external clients (e.g., a WordPress container or other services) from accessing the database.
    - "mariadb" is equal to `container_name`
4. Specify init file `init.sql` on launch, by adding `init_file = /etc/mysql/init.sql` under `[server]`


## Volumes

We need to volumes to our `docker-compose.yaml` for wordpress and nginx:

``` 
volumes:
      - ./web:/var/www/html
```

Why?
1. **Synchronization of Files**: By sharing this directory, both services work with the same set of files, ensuring WordPress operates correctly.
2. **Local Development Convenience**: Edit WordPress files and instantly reflect changes in both the Nginx and PHP containers without needing to rebuild or restart the containers.
3. **Persistence of Data**: If the containers are stopped or removed, any changes made to the files inside the container would be lost, but by mounting the /var/www/html directory to your local machine, the files are stored outside the container.

## References
1. wordpress + nginx: https://medium.com/@ssterdev/inception-guide-42-project-part-i-7e3af15eb671
2. mariadb + wordpress: https://medium.com/@ssterdev/inception-42-project-part-ii-19a06962cf3b