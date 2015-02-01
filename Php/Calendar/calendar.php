<?php

function SetFebruary($year, &$days) {
    if ($year%100 == 0) {
        if ($year%400 == 0) {
            $February = 29;
            $days = 366;
        }
        else
            $February = 28;
    }
    elseif ($year%4==0) {
        $February = 29;
        $days = 366;
    }
    else
        $February = 28;
    return $February;

}

$months = array(
    1 => 31,
    2 => 28,
    3 => 31,
    4 => 30,
    5 => 31,
    6 => 30,
    7 => 31,
    8 => 31,
    9 => 30,
    10 => 31,
    11 => 30,
    12 => 31,
);

//2014年1月1日是星期几？
$base=3;
$baseyear=2014;
$days=365;
$tmp=100;

echo "please input your year\n";
$stdin = fopen("php://stdin", "r");
$year = trim(fgets($stdin, 256));
$months[2] = SetFebruary($year, $days);


if($year < $baseyear) {
    for ($i=$baseyear; $i != $year; $i--)
        if(SetFebruary($i, $tmp) == 28)
            $base -= 1;
        else
            $base -= 2;
    $base %= 7;
} else {
    for ($i=$baseyear; $i != $year; $i--)
        if(SetFebruary($i, $tmp) == 28)
            $base += 1;
        else
            $base += 2;
    $base %= 7;
}

$first = $base;
foreach($months as $key => $mon) {
    echo "=============$year-$key================\n";
    echo "Sun\tMon\tTues\tWed\tThurs\tFri\tSat\n";
    for($i=0; $i < $first; $i++) {
        echo "\t";
    }
    for($i = 1; $i <= $mon; $i++) {
        echo "$i\t";
        $first += 1;
        if($first%7 == 0 ) {
            echo "\n";
            $first %= 7;
        }
    }
    echo "\n";
}

?>
