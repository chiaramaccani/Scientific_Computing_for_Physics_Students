# Installing an Almalinux9 container in Docker on Windows

Docker is a platform that allows you to package applications and their dependencies into isolated containers, ensuring they run consistently across different environments. It simplifies deployment, enhances scalability, and avoids compatibility issues.

With Docker, you can install and run containers with different operating systems, including **AlmaLinux 9**, which is a stable and secure Linux distribution widely used in enterprise environments.

On Windows, Docker relies on a Linux-based architecture, so installing WSL (Windows Subsystem for Linux) enables Docker to run efficiently by providing a lightweight Linux environment without requiring a full virtual machine. This is essential for running Linux-based containers like AlmaLinux 9 on Windows.

## 1. Install Windows Subsystem for Linux (WSL)

### Step 1: Enable WSL
Open PowerShell as Administrator and run:
```powershell
wsl --install
```
This will install WSL with the default Linux distribution (Ubuntu).

If you already have WSL installed but want to upgrade to WSL 2, run:
```powershell
wsl --set-default-version 2
```

### Step 2: Restart Your Computer
Some changes require a system restart.

---

## 2. Install Docker on Windows

### Step 1: Download and Install Docker Desktop
- Go to the official Docker website: [https://www.docker.com/products/docker-desktop/](https://www.docker.com/products/docker-desktop/)
- Download the latest version of **Docker Desktop for Windows**.

<p align="center">
  <img src='https://github.com/chiaramaccani/Scientific_Computing_for_Physics_Students/blob/main/task01/images/Docker01.png?raw=true' alt='Docker Image 1' style='width:1000px;'/>
</p>

- Run the installer and follow the setup instructions
- 
<p align="center">
  <img src='https://github.com/chiaramaccani/Scientific_Computing_for_Physics_Students/blob/main/task01/images/Docker02.JPG?raw=true' alt='Docker Image 2' style='width:390px;'/>
  <img src='https://github.com/chiaramaccani/Scientific_Computing_for_Physics_Students/blob/main/task01/images/Docker03.JPG?raw=true' alt='Docker Image 3' style='width:390px;'/>
</p>
- Open **Docker Desktop** and create an account (you can also use Github or Google accounts)


### Step 2: Enable WSL 2 Backend (if not done by default or if not asked during installation)
- Open **Docker Desktop**.
- Go to **Settings > General**.
- Enable **Use the WSL 2 based engine**.
- Click **Apply & Restart**.

### Step 3: Verify Docker Installation
Open a **WSL terminal** or **PowerShell** and run:
```sh
docker --version
```
If the installation was successful, it will be printed something like `Docker version 27.5.1, build 9f9e405`

---


## 3. Install Docker on Windows
- Open a **Terminal** (you can open it directly in Docker Desktop clicking on the icon in the bottom right corner)
- Download the **Almalinux9 Image**:
 ```sh
docker pull almalinux:9
```
If the command is exectued correcly, the AlmaLinux9 image should appear in Docker Desktop.
<p align="center">
  <img src='https://github.com/chiaramaccani/Scientific_Computing_for_Physics_Students/blob/main/task01/images/Docker10.JPG?raw=true' alt='Docker Image 10' style='width:1000px;'/>
</p0


- Start an new **Almalinux9 container** in interactive mode (`-it`), choosing the container name (for example `SciCompAL9`).

```sh
docker run -it --name [NAME] almalinux:9 bash
```

If the command is exectued correcly, the new container should appear in Docker Desktop.

<p align="center">
  <img src='https://github.com/chiaramaccani/Scientific_Computing_for_Physics_Students/blob/main/task01/images/Docker09.JPG?raw=true' alt='Docker Image 10' style='width:1000px;'/>
</p>

To check that the correct OS is running, check the output of the command
```sh
cat /etc/os-release
```
- To **exit** the container
```sh
exit
```
and to **stop** it
```sh
docker stop [NAME]
```
- To **start** the container again in interactive mode
```sh
docker start -ai [NAME]
```
