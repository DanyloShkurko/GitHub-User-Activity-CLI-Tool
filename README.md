# GitHub User Activity
https://roadmap.sh/projects/github-user-activity
Helps you to fetch all github events by username in relatvely readable format

## Requirements to work with tool
1. Create GitHub API key and paste it in CliHelper.cpp
2. Download httplib and paste destination to CMakeLists.txt
3. Download nlohmann

## Build 

```
cmake -B build
cmake --build build
```

## Example usage
```
./cmake-build-debug/github-activity danyloshkurko

Create : 
         -> DanyloShkurko made a Create Event on GitHub-User-Activity-CLI-Tool at 2026-1-8 at 11:41
         -> DanyloShkurko made a Create Event on Task-Tracker-CLI-Tool at 2026-0-30 at 16:50
Push : 
         -> DanyloShkurko made a Push Event on GitHub-User-Activity-CLI-Tool at 2026-1-8 at 11:45
         -> DanyloShkurko made a Push Event on Task-Tracker-CLI-Tool at 2026-1-1 at 14:59
         -> DanyloShkurko made a Push Event on Task-Tracker-CLI-Tool at 2026-0-30 at 17:24
         -> DanyloShkurko made a Push Event on Task-Tracker-CLI-Tool at 2026-0-30 at 16:55
         -> DanyloShkurko made a Push Event on Task-Tracker-CLI-Tool at 2026-0-30 at 16:53
         -> DanyloShkurko made a Push Event on Task-Tracker-CLI-Tool at 2026-0-30 at 16:52
```
