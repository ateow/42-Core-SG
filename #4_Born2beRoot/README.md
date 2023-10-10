# Born2beRoot

### VM Setup
ref video: https://www.youtube.com/watch?v=2w-2MX5QrQw\
* Grab latest Debian image: https://www.debian.org/download
* Create VM with virtualbox. Input VM name, disk size
* Select debian image to boot (Virtual Box GUI > Setting > Storage > Optical Drive disk icon)
* Select Install (no GUI)
* Input hostname: ateow42 (as per project instructions)
* Partition - select SCSI2
* Create Primary partition with mount /boot
* Create Logical partition with no mount
* Configure encrypted volumes > /dev/sda5
* Enter Encryption Password 
* Configure the logical volume manager > create partitions and mount points (as per project instrctions)

To rename Logical Volume name: `lvrename LVMGroup oldname newname`

### SUDO
* Install sudo via apt install sudo: `apt install sudo` (apt is a newer verison of apt-get)
* Add user in the sudo group: `adduser <username> sudo`
* Verify user is in sudo group: `getent group sudo`
* Install VIM to edit files: `apt install vim`

### Setup SSH (secure shell)
* Install openssh-server: `apt install openssh-server`
* Change SSH port `#Port 22` to `Port 4242` in file `/etc/ssh/sshd_config`
* Change SSH port `#PermitRootLogin prohibit-password` to `PermitRootLogin no` in file `/etc/ssh/sshd_config`

### Setup UFW (uncomplicated firewall)
* Install firewall: `apt install ufw`
* Enable firewall: `ufw enable`
* Allow port 4242 to pass firewall: `ufw allow 4242`
* Display firewall status: `ufw status`

### SUDO Group Configuration
Configure Sudoers: `vim /etc/sudoers`\
Append the following to the file:
* To limit authentication using sudo to 3 attempts: Defaults  passwd_tries=3
* Custom message: `Defaults  badpass_message="Password is wrong! Try Harder...`
* Create sudo folder and log file as per instruction: `sudo mkdir /var/log/sudo` | `touch sudo.log`
* Archived sudo commands input/output: `Defaults  log_input,log_output` (input/output will be save in default sudo io file. to specify)
* To access archieved input and output: `sudoreplay -l` or 'sudoreplay 000001' 
* To log sudo commands into sudo folder: `Defaults  logfile="/var/log/sudo/sudo.log"`
* Enable TTY mode: `Defaults  requiretty`
* To set sudo paths: `Defaults  secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin`

* Create new user42 group: `addgroup user42`
* Add user into group: `adduser <username> user42`
* Verify: `getent group user42`
  
### Configure Password Policy
* Expire every 30 days: `/etc/login.defs` > `PASS_MAX_DAYS   30`
* Min day allowed before mod set to 2: `/etc/login.defs` > `PASS_MIN_DAYS   2`
* Provide warning message 7 days before expire: `/etc/login.defs` > `PASS_WARN_AGE   7`
  
* Install a pam lib to assist: `apt install libpam-pwquality`
* Append the following into `/etc/pam.d/common-password` file 
* At least 10 chars long: `minlen=10`
* Contain at least 1 uppercase: `ucredit=-1`
* Contain at least 1 lowercase: `lcredit=-1`
* Contain at least 1 number: `dcredit=-1`
* Must not contain more then 3 consecutive identical chars: `maxrepeat=3`
* Must not include name of user: `reject_username`
* Must have at least 7 chars that are not part of former password (not for root): `difok=7`
* Enforce all above policy for root: `enforce_for_root`

`password  requisite     pam_pwquality.so  retry=3 minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root`

### Monitoring Script
Configure cron as root: `crontab -u root -e`
Configure crontab: `*/10 * * * * bash /path/to/script`
Check crontab: `crontab -u root -l`
```
#!/bin/bash
arc=$(uname -a)
pcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l) 
vcpu=$(grep "^processor" /proc/cpuinfo | wc -l)
fram=$(free -m | awk '$1 == "Mem:" {print $2}')
uram=$(free -m | awk '$1 == "Mem:" {print $3}')
pram=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
fdisk=$(df -BG | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}')
udisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}')
pdisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft*100}')
cpul=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
ctcp=$(ss -neopt state established | wc -l)
ulog=$(users | wc -w)
ip=$(hostname -I)
mac=$(ip link show | grep "ether" | awk '{print $2}')
cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
wall "	#Architecture: $arc
	#CPU physical: $pcpu
	#vCPU: $vcpu
	#Memory Usage: $uram/${fram}MB ($pram%)
	#Disk Usage: $udisk/${fdisk}Gb ($pdisk%)
	#CPU load: $cpul
	#Last boot: $lb
	#LVM use: $lvmu
	#Connections TCP: $ctcp ESTABLISHED
	#User log: $ulog
	#Network: IP $ip ($mac)
	#Sudo: $cmds cmd"
```
## Bonus

### MARIA DB
* Install mariadb-server: `apt install mariadb-server`
* Start interactive script to remove insecure default settings via sudo mysql_secure_installation.\
* `mysql_secure_installation`
```
Set root password? [Y/n] n
Remove anonymous users? [Y/n] Y
Disallow root login remotely? [Y/n] Y
Remove test database and access to it? [Y/n] Y
Reload privilege tables now? [Y/n] Y
```
* Log in to the MariaDB console via `sudo mariadb`
* CREATE DATABASE <database-name>;
* `MariaDB [(none)]> GRANT ALL ON <database-name>.* TO '<username-2>'@'localhost' IDENTIFIED BY '<password-2>' WITH GRANT OPTION;`
* Flush the privileges: `FLUSH PRIVILEGES;`

* database-name: web_database
* username: ateow
* password: 0602
* login: `mariadb -u <username-2> -p`
* `SHOW DATABASE`

### INSTALLING PHP
* `sudo apt install php-cgi php-mysql`

### INSALLING WORDPRESS
* apt install wget
* wget http://wordpress.org/latest.tar.gz -P /var/www/html
* tar -xzvf /var/www/html/latest.tar.gz
* rm /var/www/html/latest.tar.gz
* cp -r /var/www/html/wordpress/* /var/www/html
* rm -rf /var/www/html/wordpress
* cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
* in wp-config, change database, name and password
* https://127.0.0.1:8080/index.html

### LIGHTTPD
* Install lighttpd: `sudo apt install lighttpd`
* `sudo ufw allow 80`
* sudo lighty-enable-mod fastcgi
* sudo lighty-enable-mod fastcgi-php
* sudo service lighttpd force-reload

Do port fowarding. Map port 8080 to port 80\


# Evaluation
Born2beroot / Born2be0602

* DEBIAN vs ROCKY
* AppArmour vs SELINUX

AppArmour at startup:`aa-status`
Check LVM: `lsblk`
SSH:
* check ssh server installed: `dpkg -l | grep ssh`
* check ssh service status: `sudo service ssh status` / `sudo service ssh restart`
* on terminal: 'ssh ateow@127.0.0.1 -p 2222' (if issues: `rm ~/.ssh/known_hosts`)
UFW:
* check status" `ufw status`
* crontab: crontab -l\
ID	Minute	Hour	Day-Date	Month	Dayofweek\
Values	0-59	0 -23	1-31		1-12	0-6

* Change hostname: `hostnamectl set-hostname new_hostname`
* Restart your Virtual Machine.
* `sudo vim /etc/hosts` - change current hostname to new hostname
* Create new user: `sudo adduser <username>`
* Create new group: `addgroup <groupname>`
* Add user into group: `adduser <username> <groupname>`
* Verify: `getent group <groupname>`
* Change Password: `passwd <username>`

* http://127.0.0.1:8080/index.html

FTP
* ftp 127.0.0.1 -p 2121

