# Born2beRoot

ref video: https://www.youtube.com/watch?v=2w-2MX5QrQw

Step 1: Setup
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
* Install sudo via apt install sudo: `apt install sudo`
* Add user in the sudo group: `adduser <username> sudo`
* Verify user is in sudo group: `getent group sudo`
* Install VIM to edit files: `apt install vim`

###

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



### Evaluation
AppArmour at startup:
Check LVM: `lsblk`
SSH:
* on VM: 
* on terminal: 'ssh ateow@127.0.0.1 -p 2222'
