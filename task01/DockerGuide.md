# Installing WSL and Docker on Windows

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
  <img src='https://github.com/chiaramaccani/Scientific_Computing_for_Physics_Students/blob/main/task01/images/Docker01.png?raw=true' alt='Docker Image 1' style='width:500px;'/>
</p>

- Run the installer and follow the setup instructions.

### Step 2: Enable WSL 2 Backend (Recommended)
- Open **Docker Desktop**.
- Go to **Settings > General**.
- Enable **Use the WSL 2 based engine**.
- Click **Apply & Restart**.

<p align="center">
  <img src='https://github.com/chiaramaccani/Scientific_Computing_for_Physics_Students/blob/main/task01/images/Docker02.JPG?raw=true' alt='Docker Image 2' style='width:390px;'/>
  <img src='https://github.com/chiaramaccani/Scientific_Computing_for_Physics_Students/blob/main/task01/images/Docker03.JPG?raw=true' alt='Docker Image 3' style='width:390px;'/>
</p>

### Step 3: Verify Docker Installation
Open a **WSL terminal** or **PowerShell** and run:
```sh
docker --version
```
To test Docker, run:
```sh
docker run hello-world
```
If the installation is successful, you will see a message confirming that Docker is working.

---
