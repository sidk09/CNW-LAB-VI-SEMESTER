set ns [new Simulator]

set f [open out.tr w]
$ns trace-all $f
set nf [open out.nam w]
$ns namtrace-all $nf

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

$ns duplex-link $n0 $n1 1Mb 10ms DropTail
$ns duplex-link $n0 $n3 1Mb 10ms DropTail
$ns duplex-link $n2 $n1 1Mb 10ms DropTail
$ns duplex-link $n2 $n3 1Mb 10ms DropTail

$ns duplex-link-op $n0 $n1 orient right
$ns duplex-link-op $n1 $n2 orient down
$ns duplex-link-op $n2 $n3 orient left

$ns duplex-link-op $n0 $n1 color "red"
$ns duplex-link-op $n0 $n3 color "blue"
$ns duplex-link-op $n2 $n1 color "green"
$ns duplex-link-op $n2 $n3 color "yellow"

set tcp1 [new Agent/TCP]
set tcp2 [new Agent/TCP]
set tcpsink1 [new Agent/TCPSink]
set tcpsink2 [new Agent/TCPSink]
$ns attach-agent $n0 $tcp1
$ns attach-agent $n2 $tcp2
$ns attach-agent $n1 $tcpsink1
$ns attach-agent $n3 $tcpsink2

$ns connect $tcp1 $tcpsink1
$ns connect $tcp1 $tcpsink2
$ns connect $tcp2 $tcpsink1
$ns connect $tcp2 $tcpsink2

set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1
set ftp2 [new Application/FTP]
$ftp2 attach-agent $tcp2

proc finish {} {
global ns f nf 
$ns flush-trace 
close $f
close $nf
exit
}

$ns at 0.5 " $ftp1 start "
$ns at 0.5 " $ftp2 start "
$ns rtmodel-at 3.0 down $n0 $n1
$ns at 4.5 " $ftp1 stop "
$ns at 4.5 " $ftp2 stop "
$ns at 5.0 " finish "
$ns run
