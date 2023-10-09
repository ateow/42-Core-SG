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

### Evaluation
Born2beroot / Born2be0602
AppArmour at startup:
Check LVM: `lsblk`
SSH:
* check ssh server installed: `dpkg -l | grep ssh`
* check ssh service status: `sudo service ssh status` / `sudo service ssh restart`
* on terminal: 'ssh ateow@127.0.0.1 -p 2222' (if issues: `rm ~/.ssh/known_hosts`)
UFW:
* `ufw status`

Create new user:
Assign to Group:
Change Password: `passwd <username>`
