<?php

// Pascal's Triangle

echo 'Those are the estimated results for a grid of 99x99<br><br>';
for ($max = 0; $max <= 19; $max += 1) {
    $answer = 0;
    for ($i = 0; $i <= 99; $i += 1) {
        for ($j = 0; $j <= 99; $j += 1) {
            $sum_i = array_sum(str_split(strval($i)));
            $sum_j = array_sum(str_split(strval($j)));
            $sum = $sum_i + $sum_j;
            if ($sum <= $max)
                $answer += 1;
        }
    }
    echo("With a sum limit of ".$max." the cat will be able to access ".$answer." points<br>");
}

// Since it's not mentionned in the question itself, I assume it
// is infinite and the cat can access to an infinite number of coordinates.
// For example let's consider this : (100000000000,990000000000).
// Assuming again that the grid has no limit, this is still an
// accessible coordinate for the cat which means that this pattern
// can be repeated infinitely as long as the sum of the digits aren't exceeding 19.
// But I still made some tests of my own with a limited grid size (99x99)
// and I came to the results that for sum limit of 19, the cat can
// access 5995 points.
// I think it's following what is called the Pascal's Triangle pattern.