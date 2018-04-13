set ns [new Simulator]

set n0 [$ns node]
set n1 [$ns node]


$ns duplex-link $n0 $n1 1Mb 10ms RED

$ns rtmodel-at 3.0 down $n0 $n1  
$ns rtmodel-at 5.0 up $n0 $n1  

$ns at 1 "puts \"Hello World!\""
$ns at 1.5 "exit"
$ns run
