<?php
class mySQL{
        var $host;
        var $user;
        var $pass;
        var $base;
        public $dbc;
        
        public function conectar(){
                $this->host='localhost';
                $this->user='mytame';
                $this->pass='culodeostra';
                $this->base='Base_1';
                $this->dbc=mysqli_connect($this->host,$this->user,$this->pass,$this->base) or die('Error en la  conetzion \n');
                $acentos=$this->query("SET NAMES 'utf8'");
                }

        public function query($sql){
                $result=mysqli_query($this->dbc,$sql) or die('error en la consulta'.mysql_error());
                return $result;
                }

        public function query_count($table,$condicion){
                $sql="select count(*) as numr  from ".$table." ".$condicion;
                $result =  $this->query($sql);
                $row=mysqli_fetch_array($result);
                return $row['numr'];
        }

        public function query_table($campos,$nombre,$condicion){
                $tabla="<table>";
                $sql="select concat(";
                foreach($campos as $c){
                        $sql.="'<td>',".$c.",'</td>',";}
                $sql.="'') as tabla from ".$nombre." ".$condicion;
                $result=$this->query($sql);
                while($row=mysqli_fetch_array($result)){
                        $tabla.="<tr>".$row['tabla']."</tr>";}
                $tabla.="</table>";
                return $tabla;
                }
        public function query_form($area,$file){
                $name=$this->getarea($area);
                $form= "<form action=\"$file\" method=\"post\"> <p>".$name."<br><select name=\"curso\">";
                $sql="select Codigo,Name from course where Codigo like '".$area."%'";
                $result=$this->query($sql);
                while($row=mysqli_fetch_array($result)){
                        $form.='<option value="'.$row['Codigo'].'">'.$row['Name']."</option>";}
                $form.="</select><p><input type=submit value=\"Seleccionar\"><p></form>";
                return $form;
                }


        public function delete_form($matricula,$file){
                $form="<form action=\"$file\" method=\"post\"> <p> Materias seleccionadas <br><select name=\"Eliminar\">";
                $consulta="select Codigo,Name from course where convert(Codigo using utf8) in (select convert(clave using utf8) from Solicitudes where matricula='".$matricula."')";
                $result=$this->query($consulta);
                while($row=mysqli_fetch_array($result)){
                        $form.='<option value="'.$row['Codigo'].'">'.$row['Name']."</option>";}
                $form.="</Select><p><input type=submit value=\"Eliminar\"><p></form>";
                return $form;
                }

        public function getarea($area){
                $field="";
                if($area=="TC"){ $field="Tronco comun";}
                if($area=="E"){ $field="Matematicas educativas";}
                if($area=="M"){ $field="Matematicas";}
                if($area=="F"){ $field="Fisica";}
                if($area=="C"){ $field="Computacion";}
                return $field;
                }

        public function getarea($area){
                $field="";
                if($area=="TC"){ $field="Tronco comun";}
                if($area=="E"){ $field="Matematicas educativas";}
                if($area=="M"){ $field="Matematicas";}
                if($area=="F"){ $field="Fisica";}
                if($area=="C"){ $field="Computacion";}
                return $field;
                }

        public function make_form($arreglo,$file){
                $form="";
                foreach($arreglo as $a){
                        $form.="<p>".$this->query_form($a,$file)."</p>";}
                $form.="";
                return $form;
                }
        }
?>


