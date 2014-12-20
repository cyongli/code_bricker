#!/usr/bin/expect -f
set device [lindex $argv 0]
spawn mkfs.ext4 $device
expect {
  "*y,n*" { send "y\r";exp_continue}
}
interact
