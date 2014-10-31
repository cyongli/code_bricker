#!/usr/bin/perl
use strict;
use warnings;
open(my $in, "<", "a");
while(<$in>){
	if($_ =~ m!"(.*)"!){
		print "$1\n";
	}
}
