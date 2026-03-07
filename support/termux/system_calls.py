#!/data/data/com.termux/files/usr/bin/python3
import os
import shutil
import stat

# Source and destination directories
SRC_DIR = "/data/data/com.termux/files/usr/bin"
DST_DIR = "/data/data/com.termux/files/usr/local/bin/system"

# Create destination directory if it doesn't exist
os.makedirs(DST_DIR, exist_ok=True)

# Iterate over all files in source directory
for filename in os.listdir(SRC_DIR):
    src_path = os.path.join(SRC_DIR, filename)
    dst_path = os.path.join(DST_DIR, filename)

    # Skip directories
    if not os.path.isfile(src_path):
        continue

    # Check if file is executable
    if os.access(src_path, os.X_OK):
        shutil.copy2(src_path, dst_path)  # copy file and metadata
        # Ensure the copied file is executable
        st = os.stat(dst_path)
        os.chmod(dst_path, st.st_mode | stat.S_IEXEC)
        print(f"Copied: {filename}")

print(f"All system calls copied to {DST_DIR}")
#
#
