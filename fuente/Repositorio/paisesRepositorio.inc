<?php

class PaisesRepositorio
{
    public function devolverTodosPaises(){
          include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
          require_once __DIR__ . '/../../fuente/Modelo/paises.inc';
          $paises=[];
          $sql = "SELECT IdPais,NombrePais FROM Paises";
          $con = (new ConexionBaseDatos)->getConexion();
          $stmt = $con->prepare($sql);
          $stmt->execute();
          while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
            $paises[] = new Paises($row);
          }
          $stmt =null;
          $con=null;
          return $paises;
    }

    public function devolverNombrePaisPorId(int $idPais) :string{
          include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
          require_once __DIR__ . '/../../fuente/Modelo/paises.inc';
          $pais = '';
          $sql = "SELECT NombrePais FROM Paises WHERE IdPais = ?";
          $con = (new ConexionBaseDatos)->getConexion();
          $stmt = $con->prepare($sql);
          $stmt->bindParam(1,$idPais,PDO::PARAM_INT);
          $stmt->execute();
          while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
            $pais = $row['NombrePais'];
          }
          $stmt =null;
          $con=null;
          return $pais;
    }

}//fin clase
