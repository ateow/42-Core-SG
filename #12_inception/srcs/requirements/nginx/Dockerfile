FROM debian:bullseye

RUN apt-get update && \
	apt-get  -y install nginx && \
	apt-get install openssl

#COPY ./html /usr/share/nginx/html
# this command copies the html files

#COPY ./nginx.conf /usr/share/nginx/html

COPY ./nginx.conf /etc/nginx/conf.d
#RUN sed -i '/http {/a\    include /usr/share/nginx/html/nginx.conf;' /etc/nginx/nginx.conf
# this command inserts the conf settings into nginx.conf file

RUN mkdir -p /etc/nginx/ssl

RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
	-out /etc/nginx/ssl/ateow.crt \
	-keyout /etc/nginx/ssl/ateow.key \
	-subj "/CN=ateow.42.fr/"

#    openssl req: This invokes the OpenSSL command-line tool for generating certificate signing requests (CSRs) and self-signed certificates.
#   -newkey rsa:4096: This option specifies that a new RSA private key should be generated with a key size of 4096 bits.
#    -x509: This option specifies that a self-signed certificate should be generated instead of a CSR. For production, we should buy a proper cert so that browsers trust the site. self-signed cert is not trusted by browsers
#   -sha256: This specifies the hash algorithm to use for the certificate signature, in this case SHA-256.
#   -days 365: This specifies the validity period of the certificate in days. In this example, the certificate will be valid for 365 days.
#   -nodes: This option tells OpenSSL not to encrypt the private key. Without this option, OpenSSL would prompt for a passphrase to encrypt the private key, but in this case, we're generating a self-signed certificate, so encryption is unnecessary.
#   -out /etc/nginx/ssl/ateow.crt: This specifies the output file where the generated certificate will be saved. In this case, it will be saved as /etc/nginx/ssl/ateow.crt.
#   -keyout /etc/nginx/ssl/ateow.key: This specifies the output file where the generated private key will be saved. In this case, it will be saved as /etc/nginx/ssl/ateow.key.
#   -subj "/CN=ateow.42.fr/": This specifies the subject of the certificate, which includes information such as the common name (CN) of the entity the certificate represents. In this case, the common name is set to ateow.42.fr.

EXPOSE	443

CMD ["nginx", "-g", "daemon off;"]

# This command gets nginx to run in the foreground instead of a background
# if NGINX is running as a background process (daemon) without any other foreground process to keep the container alive, there's a possibility that Docker might terminate the container soon after NGINX starts.
# In the case of NGINX running as a background process without any other foreground process, Docker might incorrectly interpret NGINX as the main process, and because there is no foreground process, it leads to premature termination of the container if NGINX exits unexpectedly or goes into an idle state.

