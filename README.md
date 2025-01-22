# Concurrent News Broadcasting System 📺 

## Introduction 🌟
This project implements a sophisticated news broadcasting system demonstrating concurrent programming and synchronization mechanisms in C++. The system simulates a real-world news organization with multiple components working together to process and broadcast news stories.

## System Architecture 🏗️
The system consists of several key components working in parallel:

### Components 🔄
- **Producers** 📰: Generate various types of news stories:
  - Sports News 🏈
  - Weather Updates 🌤️
  - General News 📋
  
- **Dispatcher** 📬: Routes news stories to appropriate queues based on category

- **Co-Editors** ✍️: Process and refine news stories before broadcast

- **Screen Manager** 🎥: Handles the final display of edited news stories

### Technical Features 🛠️
- **Bounded Buffer Implementation** 📦
  - Thread-safe communication between components
  - Efficient memory management
  - Overflow protection

- **Synchronization Mechanisms** 🔒
  - Semaphore-based thread coordination
  - Deadlock prevention
  - Race condition handling

## Prerequisites 📋
Before running the system, ensure you have:
- C++11 or later ⚙️
- g++ compiler with pthread support 🔧
- Make utility 🛠️

## Installation Guide 💻

### 1. Install Required Tools
For Ubuntu/Debian systems:
```bash
sudo apt-get update
sudo apt-get install g++ make
```

### 2. Clone the Repository 📥
```bash
git clone https://github.com/YZohar8/Concurrent-Programming-and-Synchronization-Mechanisms.git
cd Concurrent-Programming-and-Synchronization-Mechanisms
```

### 3. Build the Project 🔨
```bash
make
```

### 4. Run the System 🚀
Choose from available configuration files:
```bash
./ex4.out config1.txt  # For configuration 1
./ex4.out config2.txt  # For configuration 2
./ex4.out config3.txt  # For configuration 3
```

## Configuration Files 📝
The system comes with three preset configuration files:
- **config1.txt**: Basic setup with minimal producers
- **config2.txt**: Medium-scale system with balanced components
- **config3.txt**: Large-scale setup with maximum concurrent operations

Want to create your own configuration? Add new `.txt` files to the root directory following the same format! 🎯

## Project Structure 📁
```
project/
├── src/
│   ├── BoundedBuffer.cpp
│   ├── BoundedBuffer.h
│   ├── Producer.cpp
│   ├── Producer.h
│   ├── Dispatcher.cpp
│   ├── Dispatcher.h
│   ├── CoEditor.cpp
│   ├── CoEditor.h
│   ├── ScreenManager.cpp
│   └── ScreenManager.h
│   ├── config1.txt
│   ├── config2.txt
│   └── config3.txt
├── Makefile
└── README.md
```

## Key Features ⭐
- **Multi-threaded Architecture** 🔄
- **Real-time News Processing** ⚡
- **Dynamic Load Balancing** ⚖️
- **Configurable System Parameters** ⚙️
- **Robust Error Handling** 🛡️

## Performance Tips 🚀
1. Adjust buffer sizes in configuration files for optimal performance
2. Monitor system resource usage during execution
3. Fine-tune thread counts based on your hardware capabilities

## Troubleshooting 🔧
- **Compilation Issues**: Ensure g++ and pthread are properly installed
- **Runtime Errors**: Check configuration file format
- **Performance Problems**: Adjust buffer sizes and thread counts

## Contributing 🤝
Contributions are welcome! Feel free to:
- Submit bug reports 🐛
- Propose new features ✨
- Send pull requests 📤

## License 📄
This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments 🙏
- Thanks to all contributors who helped develop this system
- Special thanks to the concurrent programming community

## Contact 📫
For questions or support, please open an issue in the repository.

Happy News Broadcasting! 📺 ✨
