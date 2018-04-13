set ns [new Simulator]

set f [open out.tr w]
$ns trace-all $f
set nf [open out.nam w]
$ns namtrace-all $nf

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]
set n7 [$ns node]
set n8 [$ns node]
set n9 [$ns node]
set n10 [$ns node]
set n11 [$ns node]

$ns duplex-link $n0 $n1 1.5Mb 40ms DropTail
$ns duplex-link $n0 $n2 10Mb 20ms DropTail
$ns duplex-link $n0 $n3 10Mb 20ms DropTail
$ns duplex-link $n0 $n4 10Mb 20ms DropTail
$ns duplex-link $n0 $n5 10Mb 20ms DropTail
$ns duplex-link $n0 $n6 10Mb 20ms DropTail
$ns duplex-link $n1 $n7 10Mb 20ms DropTail
$ns duplex-link $n1 $n8 10Mb 20ms DropTail
$ns duplex-link $n1 $n9 10Mb 20ms DropTail
$ns duplex-link $n1 $n10 10Mb 20ms DropTail
$ns duplex-link $n1 $n11 10Mb 20ms DropTail

$ns duplex-link-op $n0 $n1 orient left
$ns duplex-link-op $n0 $n2 orient up
$ns duplex-link-op $n0 $n3 orient right-up
$ns duplex-link-op $n0 $n4 orient right
$ns duplex-link-op $n0 $n5 orient right-down
$ns duplex-link-op $n0 $n6 orient down
$ns duplex-link-op $n1 $n7 orient up
$ns duplex-link-op $n1 $n8 orient left-up
$ns duplex-link-op $n1 $n9 orient left
$ns duplex-link-op $n1 $n10 orient left-down
$ns duplex-link-op $n1 $n11 orient down

$n0 color black
$n1 color black
$n2 color blue
$n3 color violet
$n4 color red
$n5 color orange
$n6 color green
$n7 color dodgerblue
$n8 color darkviolet
$n9 color pink
$n10 color yellow
$n11 color darkgreen

$ns duplex-link-op $n0 $n1 color "black"
$ns duplex-link-op $n0 $n2 color "blue"
$ns duplex-link-op $n0 $n3 color "violet"
$ns duplex-link-op $n0 $n4 color "red"
$ns duplex-link-op $n0 $n5 color "orange"
$ns duplex-link-op $n0 $n6 color "green"
$ns duplex-link-op $n1 $n7 color "dodgerblue"
$ns duplex-link-op $n1 $n8 color "darkviolet"
$ns duplex-link-op $n1 $n9 color "pink"
$ns duplex-link-op $n1 $n10 color "yellow"
$ns duplex-link-op $n1 $n11 color "darkgreen"

set tcp1 [new Agent/TCP]
set tcp2 [new Agent/TCP]
set tcp3 [new Agent/TCP]
set tcp4 [new Agent/TCP]
set tcp5 [new Agent/TCP]
set tcp6 [new Agent/TCP]
set tcpsink1 [new Agent/TCPSink]
set tcpsink2 [new Agent/TCPSink]
set tcpsink3 [new Agent/TCPSink]
set tcpsink4 [new Agent/TCPSink]
set tcpsink5 [new Agent/TCPSink]
set tcpsink6 [new Agent/TCPSink]

$ns attach-agent $n8 $tcp1
$ns attach-agent $n8 $tcp2
$ns attach-agent $n8 $tcp3
$ns attach-agent $n8 $tcp4
$ns attach-agent $n8 $tcp5
$ns attach-agent $n8 $tcp6
$ns attach-agent $n2 $tcpsink1
$ns attach-agent $n3 $tcpsink2
$ns attach-agent $n4 $tcpsink3
$ns attach-agent $n5 $tcpsink4
$ns attach-agent $n6 $tcpsink5
$ns attach-agent $n0 $tcpsink6

$ns connect $tcp1 $tcpsink1
$ns connect $tcp2 $tcpsink2
$ns connect $tcp3 $tcpsink3
$ns connect $tcp4 $tcpsink4
$ns connect $tcp5 $tcpsink5
$ns connect $tcp6 $tcpsink6

set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1
set ftp2 [new Application/FTP]
$ftp2 attach-agent $tcp2
set ftp3 [new Application/FTP]
$ftp3 attach-agent $tcp3
set ftp4 [new Application/FTP]
$ftp4 attach-agent $tcp4
set ftp5 [new Application/FTP]
$ftp5 attach-agent $tcp5
set ftp6 [new Application/FTP]
$ftp6 attach-agent $tcp6

proc finish {} {
global ns f nf 
$ns flush-trace 
close $f
close $nf
exit
}

$ns at 0.5 " $ftp1 start "
$ns at 0.5 " $ftp2 start "
$ns at 0.5 " $ftp3 start "
$ns at 0.5 " $ftp4 start "
$ns at 0.5 " $ftp5 start "
$ns at 0.5 " $ftp6 start "
$ns at 4.5 " $ftp1 stop "
$ns at 4.5 " $ftp2 stop "
$ns at 4.5 " $ftp3 stop "
$ns at 4.5 " $ftp4 stop "
$ns at 4.5 " $ftp5 stop "
$ns at 4.5 " $ftp6 stop "
$ns at 5.0 " finish "
$ns run
