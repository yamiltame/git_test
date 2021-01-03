$tabla=<<<EOT
        <table>
        <tr>
          <td><a href="mapa.php?z=$nivel&x=$latitud1&y=$altitud1"/><img src='image.php?x=$x&y=$y&z=$z'/></a></td>
          <td><a href="mapa.php?z=$nivel&x=$latitud2&y=$altitud1"/><img src='image.php?x=$xx&y=$y&z=$z'/></a></td>
        </tr>
        <tr>
          <td><a href="mapa.php?z=$nivel&x=$latitud1&y=$altitud2"/><img src='image.php?x=$x&y=$yy&z=$z'/></a></td>
          <td><a href="mapa.php?z=$nivel&x=$latitud2&y=$altitud2"/><img src='image.php?x=$xx&y=$yy&z=$z'/></a><td>
        </tr>
</table>
EOT;

echo $tabla;

