🌐 C TCP Port Scanner

A simple TCP port scanner written in C that scans a target IP address over a specified range of ports and identifies open ports.

⚠️ For educational and authorized testing purposes only.

📌 Description

This program:

Takes a target IP address as input

Accepts a start and end port range

Attempts TCP connections to each port

Identifies which ports are open

Displays total number of open ports

It uses low-level socket programming concepts in C.

🛠 Technologies & Libraries Used

stdio.h

stdlib.h

string.h

unistd.h

arpa/inet.h

sys/socket.h

netinet/in.h

🚀 How It Works

User enters:

Target IP address

Starting port

Ending port

Program validates the port range.

For each port in the range:

Creates a TCP socket

Attempts to connect using connect()

If connection succeeds → port is OPEN.

Displays total number of open ports after scan completes.

💻 Compilation & Execution
🔹 Linux / macOS
gcc port_scanner.c -o port_scanner
./port_scanner


⚠️ This program uses POSIX socket libraries and will not compile natively on Windows without WSL or modifications.

🧪 Example Run
Enter target IP: 127.0.0.1
Enter start port: 20
Enter end port: 100

Scanning 127.0.0.1 from port 20 to 100...

Port 22 OPEN
Port 80 OPEN

Scan complete.
Total open ports: 2

🧠 Concepts Demonstrated

TCP socket programming

IPv4 addressing

Network byte order (htons)

Port scanning fundamentals

Basic input validation

System calls (socket, connect, close)

⚠️ Ethical & Legal Notice

This tool should only be used:

On systems you own

On networks you have explicit permission to test

Unauthorized port scanning may violate laws and network policies.

📈 Possible Improvements

Add timeout handling (currently blocks on filtered ports)

Add multi-threading for faster scanning

Add service detection (banner grabbing)

Support hostname resolution

Add stealth scanning techniques

Export results to a file

📜 License

This project is intended for educational use in networking and cybersecurity learning.
