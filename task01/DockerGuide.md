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

### Step 3: Verify Installation
After restarting, open a new PowerShell window and check the installed distributions:
```powershell
wsl -l -v
```
If no distributions are installed, you can manually install Ubuntu with:
```powershell
wsl --install -d Ubuntu
```

---

## 2. Install Docker on Windows

### Step 1: Download and Install Docker Desktop
- Go to the official Docker website: [https://www.docker.com/products/docker-desktop/](https://www.docker.com/products/docker-desktop/)
- Download the latest version of **Docker Desktop for Windows**.
- Run the installer and follow the setup instructions.

### Step 2: Enable WSL 2 Backend (Recommended)
- Open **Docker Desktop**.
- Go to **Settings > General**.
- Enable **Use the WSL 2 based engine**.
- Click **Apply & Restart**.

### Step 3: Add Your Linux Distribution to Docker
- In **Docker Desktop**, go to **Settings > Resources > WSL Integration**.
- Enable integration for your preferred WSL distribution (e.g., Ubuntu).
- Click **Apply & Restart**.

### Step 4: Verify Docker Installation
Open a **WSL terminal** (Ubuntu) or **PowerShell** and run:
```sh
docker --version
```
To test Docker, run:
```sh
docker run hello-world
```
If the installation is successful, you will see a message confirming that Docker is working.

---

## 3. Additional Commands

### Check Installed WSL Versions
```powershell
wsl -l -v
```

### Set Default WSL Version to 2
```powershell
wsl --set-default-version 2
```

### Update WSL Kernel (If Needed)
If you encounter errors, update the WSL kernel:
```powershell
wsl --update
```

---

## 4. Uninstalling WSL or Docker

### Uninstall WSL
```powershell
wsl --unregister <DistroName>
```
To remove WSL completely:
1. Open **Control Panel > Programs and Features**.
2. Uninstall **Windows Subsystem for Linux Update**.
3. Disable WSL in PowerShell:
   ```powershell
   dism.exe /online /disable-feature /featurename:Microsoft-Windows-Subsystem-Linux /norestart
   ```

### Uninstall Docker
- Open **Control Panel > Programs and Features**.
- Find **Docker Desktop** and click **Uninstall**.

---

## 5. Troubleshooting

### WSL Installation Issues
- If `wsl --install` fails, manually install it from the Microsoft Store.
- Ensure **Virtualization** is enabled in BIOS.
- Run `wsl --update` to get the latest kernel.

### Docker Issues
- Make sure **WSL 2 Backend** is enabled in Docker settings.
- Restart **Docker Desktop** and **WSL** (`wsl --shutdown`).
- Ensure your Linux distribution is running on WSL 2 (`wsl -l -v`).
