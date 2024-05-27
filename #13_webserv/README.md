# webserv
42 Webserv group project working repository

===========================================================================================================

Configuration

Search for the HTTP response status codes list on the internet. During this evaluation, if any status codes is wrong, don't give any related points.

>>>>> Setup multiple servers with different ports.

clear && make re && ./webserv ./configs/diff_ports.conf
# only 2 server started because server1 and server3 similar port
curl http://127.0.0.1:8080
curl http://127.0.0.1:8081

>>>>> Setup multiple servers with different hostnames (use something like: curl --resolve example.com:80:127.0.0.1 http://example.com/).

curl --resolve example.com:8080:127.0.0.1 http://example.com:8080/
curl --resolve hello.com:8081:127.0.0.1 http://hello.com:8081/

>>>>> Setup default error page (try to change the error 404).

clear && make re && ./webserv ./configs/error.conf
curl http://127.0.0.1:8080/filenotfound
curl http://127.0.0.1:8081/filenotfound
# port 8080 no entry for error pages. default to be used
# port 80801 entry change for 404. 

>>>>> Limit the client body (use: curl -X POST -H "Content-Type: plain/text" --data "BODY IS HERE write something shorter or longer than body limit").

clear && make re && ./webserv ./configs/error.conf
curl -X POST -H "Content-Type: plain/text" --data "hello world" http://127.0.0.1:8080
curl -X POST -H "Content-Type: plain/text" --data "hello world" http://127.0.0.1:8081
# adjust data size to prove limit exist

>>>>> Setup routes in a server to different directories.
>>>>> Setup a default file to search for if you ask for a directory.

clear && make re && ./webserv ./configs/diff_dir.conf
curl http://127.0.0.1:8080
curl http://127.0.0.1:8080/index.html
curl http://127.0.0.1:8081
curl http://127.0.0.1:8081/index.html

>>>>> Setup a list of methods accepted for a certain route (e.g., try to delete something with and without permission).

clear && make re && ./webserv ./configs/diff_methods.conf
curl http://127.0.0.1:8080
curl http://127.0.0.1:8081
# 8080 GET POST DELETE allowed
# 8081 GET not allowed. only POST
curl -X INVALIDMETHOD http://127.0.0.1:8080
curl -X invalidmethod http://127.0.0.1:8080
curl -X DELETE http://127.0.0.1:8080/file_to_be_deleted
curl -X DELETE http://127.0.0.1:8081/file_to_be_deleted
chmod 000 ./eval_directories/directory1/no_permission_file
curl -X DELETE http://127.0.0.1:8080/no_permission_file

===========================================================================================================

Basic checks

Using telnet, curl, prepared files, demonstrate that the following
features work properly:

>>>>> GET, POST and DELETE requests should work.
>>>>> UNKNOWN requests should not result in a crash.
>>>>> For every test you should receive the appropriate status code.
>>>>> Upload some file to the server and get it back.

clear && make re && ./webserv ./configs/upload.conf
for i in {1..10000}; do curl -F 'test_upload=@/home/cooi/Documents/42sg/Core/webserv/upload_img_jechoo.jpeg' http://127.0.0.1:8080/upload; done
curl -F 'test_upload=@/home/ateow/Desktop/webserv/upload_img_jechoo.jpeg' http://127.0.0.1:8080/upload
curl -F 'test_upload=@/home/ateow/Desktop/webserv/upload_text.txt' http://127.0.0.1:8080/upload
curl -F 'test_upload=@/home/ateow/Desktop/webserv/upload_text.txt' http://127.0.0.1:8081/upload
# 8081 limit size of 1. will return 413

===========================================================================================================

Check CGI

Pay attention to the following:

>>>>>The server is working fine using a CGI.
>>>>>The CGI should be run in the correct directory for relative path file access.
>>>>>With the help of the students you should check that everything is working properly. You have to test the CGI with the "GET" and "POST" methods.
>>>>>You need to test with files containing errors to see if the error handling works properly. You can use a script containing an infinite loop or an error; you are free to do whatever tests you want within the limits of acceptability that remain at your discretion. The group being evaluated should help you with this.

clear && make re && ./webserv ./configs/cgi.conf
curl -X GET "http://127.0.0.1:8080/cgi-bin/process_data.cgi?age=12&name=aaron"
curl -X POST "http://127.0.0.1:8080/cgi-bin/process_data.cgi" -d "name=aaron&age=12"
curl -X POST http://127.0.0.1:8080/cgi-bin/infinite_loop.cgi
curl -X POST http://127.0.0.1:8080/cgi-bin/runtime_error.cgi
curl -X POST http://127.0.0.1:8080/cgi-bin/static_page.cgi

===========================================================================================================

The server should never crash and an error should be visible in case of a problem.

Check with a browser

>>>>> Use the reference browser of the team. Open the network part of it, and try to connect to the server using it.

clear && make re && ./webserv ./configs/base.conf
http://127.0.0.1:8080/

Look at the request header and response header.
It should be compatible to serve a fully static website.
>>>>> Try a wrong URL on the server.

http://127.0.0.1:8080/wrongURL

>> Try to list a directory.

http://127.0.0.1:8081/

>> Try a redirected URL.

http://127.0.0.1:8081/old_home
http://127.0.0.1:8081/old_home2
http://127.0.0.1:8081/old_home999

>> Try anything you want to.

===========================================================================================================

Port issues

>>>>> In the configuration file setup multiple ports and use different websites. Use the browser to ensure that the configuration works as expected and shows the right website.
>>>>> In the configuration, try to setup the same port multiple times. It should not work.

clear && make re && ./webserv ./configs/diff_ports.conf
# only 2 server started because server1 and server3 similar port
http://127.0.0.1:8080
http://127.0.0.1:8081

>>>>> Launch multiple servers at the same time with different configurations but with common ports. Does it work? If it does, ask why the server should work if one of the configurations isn't functional. Keep going.

clear && make re && ./webserv ./configs/invalid.conf 
# invalid port and invalid root_directory

===========================================================================================================

Siege & stress test

>>>>> Use Siege to run some stress tests.
>>>>> Availability should be above 99.5% for a simple GET on an empty page with a siege -b on that page.
>>>>> Verify there is no memory leak (Monitor the process memory usage. It should not go up indefinitely).
>>>>> Check if there is no hanging connection.
>>>>> You should be able to use siege indefinitely without having to restart the server (take a look at siege -b).

siege -v -r 255 -c 200 http://127.0.0.1:8080
htop



END
===========================================================================================================
























//


Error Handling:

METHODS:
* if not upper case: return 400
* if uppercase but method not recongise: return 405


┌──(kali㉿kali)-[~/Desktop/webserv]\
└─$ curl -I -X GET http://127.0.0.1/ \
HTTP/1.1 200 OK\
Server: nginx/1.24.0\

┌──(kali㉿kali)-[~/Desktop/webserv]\
└─$ curl -I -X Get http://127.0.0.1/ \
HTTP/1.1 400 Bad Request\
Server: nginx/1.24.0\

┌──(kali㉿kali)-[~/Desktop/webserv]\
└─$ curl -I -X XXX http://127.0.0.1/ \
HTTP/1.1 405 Not Allowed\
Server: nginx/1.24.0\

┌──(kali㉿kali)-[~/Desktop/webserv]\
└─$ curl -I -X GET1 http://127.0.0.1/ \
HTTP/1.1 400 Bad Request\
Server: nginx/1.24.0\

