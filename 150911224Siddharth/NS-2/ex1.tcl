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

$ns duplex-link $n0 $n4 1Mb 10ms DropTail
$ns duplex-link $n1 $n4 1Mb 10ms DropTail
$ns duplex-link $n2 $n4 1Mb 10ms DropTail
$ns duplex-link $n3 $n4 1Mb 10ms DropTail

$ns duplex-link-op $n0 $n4 orient right-down
$ns duplex-link-op $n1 $n4 orient right-up
$ns duplex-link-op $n2 $n4 orient left-up
$ns duplex-link-op $n3 $n4 orient left-down

set udp1 [new Agent/UDP]
$ns attach-agent $n0 $udp1
set null1 [new Agent/Null]
$ns attach-agent $n3 $null1
$ns connect $udp1 $null1

set cbr1 [new Application/Traffic/CBR]
$cbr1 attach-agent $udp1

set udp2 [new Agent/UDP]
$ns attach-agent $n1 $udp2
set null2 [new Agent/Null]
$ns attach-agent $n2 $null2
$ns connect $udp2 $null2

set cbr2 [new Application/Traffic/CBR]
$cbr2 attach-agent $udp2

proc finish {} {
global ns f nf 
$ns flush-trace 
close $f
close $nf
exit
}

$ns at 0.1 " $cbr1 start "
$ns at 0.1 " $cbr2 start "
$ns at 10.1 " $cbr1 stop "
$ns at 10.1 " $cbr2 stop "
$ns at 10.5 " finish "

$ns run
