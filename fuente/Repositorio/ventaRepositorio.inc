<?php

class VentaRepositorio
{
  //para insertar la venta
  public function insertarVenta(string $userNombre, float $precioTotal) :bool{
        include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
        //$fecha = date('Y-m-d h:i:s');
        $respuesta = false;
        $sql = "INSERT INTO Venta(Total,FechaCompra,Usuario) VALUES(?,GETDATE(),?);";
        try{
            $con = (new ConexionBaseDatos)->getConexion();
            $con->beginTransaction();
            $stmt = $con->prepare($sql);
            $stmt->bindParam(1,$precioTotal,PDO::PARAM_INT);
            //$stmt->bindParam(2,$fecha,PDO::PARAM_STR);
            $stmt->bindParam(2,$userNombre,PDO::PARAM_STR);
            if($stmt->execute()){
              $respuesta = true;
            }
            $con->commit();
            return $respuesta;
        }catch(PDOException $ex){
           throw $ex;
           $con->rollBack();
        }finally{
          $con = null;
          $stmt = null;
        }
  }//fin metodo

  public function sacarIdVenta(string $userNombre) :int{
    include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
    //Esta sentencia es para que saque la ultima venta introducida
    $sql = "SELECT TOP 1 IdVenta,FechaCompra FROM Venta WHERE usuario = ? ORDER BY FechaCompra DESC;";
    $idVenta = 0;
        $con = (new ConexionBaseDatos)->getConexion();
        $stmt = $con->prepare($sql);
        $stmt->bindParam(1,$userNombre,PDO::PARAM_STR);
        $stmt->execute();
        while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
            $idVenta = $row['IdVenta'];
        }
		$stmt = null;
		$con = null;
        return $idVenta;
  }//fin metodo

  public function devolverListaUsuariosTienda(int $idTienda) :array{
    include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
    include_once __DIR__ . '/../../fuente/modelo/usuario.inc';
    $con = (new ConexionBaseDatos)->getConexion();
    $sql = "SELECT DISTINCT Usuario.Usuario,Usuario.Contrasenia,Usuario.IdGrupoUsuario,Usuario.Nombre,Usuario.PrimerApellido,
            Usuario.SegundoApellido,
            Usuario.IdCiudad,Usuario.Telefono,Usuario.Direccion,Usuario.Nif,Usuario.Fax,Usuario.Email,Usuario.Activo
            FROM Usuario
            JOIN Venta ON Venta.Usuario = Usuario.Usuario
            JOIN DetalleVenta ON DetalleVenta.IdVenta = Venta.IdVenta
            WHERE DetalleVenta.IdTienda = ?;";
    $user=[];
    $stmt = $con->prepare($sql);
		$stmt->bindParam(1,$idTienda,PDO::PARAM_INT);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$user[] = new Usuario($row);
		}
		$stmt = null;
		$con = null;
		return $user;

  }



}//fin clase
