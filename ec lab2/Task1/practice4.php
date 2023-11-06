<!DOCTYPE html>
<html>
<body>

<form method="post" action="<?php echo $_SERVER['PHP_SELF'];?>">
  <label for="number">Enter a number:</label><br>
  <input type="number" id="number" name="number" min="1" required><br>
  <input type="submit">
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $num = $_POST['number'];

    echo "<table border='1'>";
    echo "<tr><th></th>";
    for ($i = 1; $i <= $num; $i++) {
        echo "<th>$i</th>";
    }
    echo "</tr>";

    for ($i = 1; $i <= $num; $i++) {
        echo "<tr><th>$i</th>";
        for ($j = 1; $j <= $num; $j++) {
            echo "<td>" . $i*$j . "</td>";
        }
        echo "</tr>";
    }
    echo "</table>";
}
?>

</body>
</html>
