<?php
require_once('conexion.php');
$conexion = new mySQL();
$conexion->conectar();
$formulario=<<<EOT
<form action="test.php" method='get'>
        matricula:<br>
        <input type="text" name="m"><br>
        <input type="submit" value="ingresar"><br>
</form>
EOT;
if($conexion->query_count('Fismatusers',"where Matricula='".$_POST['m']."'")>0){}

if(isset($_POST['matricula'])){
        $temp=$_POST['matricula'];
        $table="Fismatusers";
        $condicionmat="where Matricula ='".$_POST['matricula']."'";
        $mat=$conexion->query_count($table,$condicionmat);
        if($mat==1){
                echo $conexion->query_form("","test.php?m=$temp");}
        else{echo "usuario invalido";}
        }

if(isset($_POST['matricula'])){
        if($conexion->query_count('Fismatusers',"where Matricula='".$_GET['m']."'")==1){
                if(isset($_POST['Eliminar'])){
                        $del="delete from Solicitudes where clave='".$_POST['Eliminar']."'";
                        $conexion->query($del);
                        }
                $temp=$_GET['m'];
                $solicitudes=$conexion->query_count('Solicitudes',"where matricula='".$temp."'");
                if($solicitudes<7){
                        if(isset($_POST['curso'])){
                                $sql="insert into Solicitudes values ('".$_GET['m']."','".$_POST['curso']."')";
                                $conexion->query($sql);}
                        $condicion="where convert(Codigo using utf8) in (select convert(clave using utf8) from Solicitudes where matricula='".$_GET['m']."')";
                        $materias=$conexion->query_table(array("Name"),"courseold",$condicion);
                        echo $materias;
                        echo $conexion->query_form("","test.php?m=$temp");

                        }
                else{
                        echo "ya solicitaste muchas materias";
                        echo $conexion->delete_form($temp,"test.php?m=$temp");
                        }
                }
        else{
                echo 'usuario invalido';
                echo $formulario;
                echo $formulario;
                }
        }
else{echo $formulario;}

?>


