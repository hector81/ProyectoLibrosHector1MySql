<?php

class DetallesVentaRepositorio
{
	public function insertarLineaVenta(int $idVenta,array $carrito) :bool{
		$sql ="INSERT INTO DetalleVenta(IdVenta,IdEjemplar,Cantidad,PVP,IdTienda) VALUES(?,?,?,?,?);";
		$respuesta = false;
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		foreach ($carrito as $key => $value) {
			$idArticulo = $value->getIdEjemplar();
			$cantidad = $value->getCantidad();
			$pc = $value->getPReserva();
			$idTienda = $value->getIdTienda();
			try{
				$con = (new ConexionBaseDatos)->getConexion();
				$con->beginTransaction();
				$stmt = $con->prepare($sql);
				$stmt->bindParam(1,$idVenta,PDO::PARAM_INT);
				$stmt->bindParam(2,$idArticulo,PDO::PARAM_INT);
				$stmt->bindParam(3,$cantidad,PDO::PARAM_INT);
				$stmt->bindParam(4,$pc,PDO::PARAM_INT);
				$stmt->bindParam(5,$idTienda,PDO::PARAM_INT);
				if($stmt->execute()){
				  $respuesta = true;
				}
				$con->commit();

			}catch(PDOException $ex){
			   throw $ex;
			   $con->rollBack();
			}finally{
			  $con = null;
			  $stmt = null;
			}
		}//fin del foreach
		return $respuesta;
	}//fin metodo

	public function devolverLineasVentaCliente(string $usuario) :array{
		$sql = "SELECT DetalleVenta.IdEjemplar,DetalleVenta.Cantidad,
						Ejemplares.PVP,
						DetalleVenta.IdTienda,Venta.FechaCompra
						,DetalleVenta.Activo,DetalleVenta.Nulo
						FROM Venta
						JOIN DetalleVenta ON DetalleVenta.IdVenta = Venta.IdVenta
						JOIN Ejemplares ON Ejemplares.IdEjemplar = DetalleVenta.IdEjemplar
						WHERE Venta.Usuario = ?;";
		$arrayLinea=[];
		include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$usuario,PDO::PARAM_STR);
		$stmt->execute();
		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
			$arrayLinea[] = [
				'IdEjemplar' => $row['IdEjemplar'],
				'Cantidad' => $row['Cantidad'],
				'PVP' => $row['PVP'],
				'IdTienda' => $row['IdTienda'],
				'FechaCompra' => $row['FechaCompra'],
				'Activo' => $row['Activo'],
				'Nulo' => $row['Nulo']
			];
		}
		$con = null;
		$stmt = null;
		return $arrayLinea;
	}//fin metodo

	public function devolverTodasLasVentasClientes() :array{
		$sql = "SELECT DetalleVenta.IdEjemplar,DetalleVenta.Cantidad,Ejemplares.PVP,DetalleVenta.IdTienda,Venta.FechaCompra , Venta.Usuario
						,DetalleVenta.Activo,DetalleVenta.IdVenta,Tiendas.Nombre,DetalleVenta.Nulo
						FROM Venta
						JOIN DetalleVenta ON DetalleVenta.IdVenta = Venta.IdVenta
						JOIN Ejemplares ON Ejemplares.IdEjemplar = DetalleVenta.IdEjemplar
						JOIN Tiendas ON Tiendas.IdTienda = DetalleVenta.IdTienda";
		$arrayLinea=[];
		include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->execute();
		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
			$arrayLinea[] = [
				'IdEjemplar' => $row['IdEjemplar'],
				'Cantidad' => $row['Cantidad'],
				'PVP' => $row['PVP'],
				'IdTienda' => $row['IdTienda'],
				'FechaCompra' => $row['FechaCompra'],
				'Usuario' => $row['Usuario'],
				'Activo' => $row['Activo'],
				'IdVenta' => $row['IdVenta'],
				'Nombre' => $row['Nombre'],
				'Nulo' => $row['Nulo'],
			];
		}
		$con = null;
		$stmt = null;
		return $arrayLinea;
	}//fin metodo

	public function devolverTodasLasVentasTienda(int $idTienda) :array{
		$sql = "SELECT DetalleVenta.IdEjemplar,DetalleVenta.Cantidad,Ejemplares.PVP,DetalleVenta.IdTienda,Venta.FechaCompra, Venta.Usuario
						,DetalleVenta.Activo,DetalleVenta.IdVenta,DetalleVenta.Nulo
						FROM Venta
						JOIN DetalleVenta ON DetalleVenta.IdVenta = Venta.IdVenta
						JOIN Ejemplares ON Ejemplares.IdEjemplar = DetalleVenta.IdEjemplar
						WHERE DetalleVenta.IdTienda = ?;";
		$arrayLinea=[];
		include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$idTienda,PDO::PARAM_INT);
		$stmt->execute();
		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
			$arrayLinea[] = [
				'IdEjemplar' => $row['IdEjemplar'],
				'Cantidad' => $row['Cantidad'],
				'PVP' => $row['PVP'],
				'IdTienda' => $row['IdTienda'],
				'FechaCompra' => $row['FechaCompra'],
				'Usuario' => $row['Usuario'],
				'Activo' => $row['Activo'],
				'IdVenta' => $row['IdVenta'],
				'Nulo' => $row['Nulo']
			];
		}
		$con = null;
		$stmt = null;
		return $arrayLinea;
	}//fin metodo

	public function devolverTitulosLineaVenta(array $compras) :array{
		$titulos = [];
		include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
		$sql = "SELECT Libros.Titulo AS TITULO_LIBRO FROM Libros
			JOIN Ejemplares ON Ejemplares.IdLibro = Libros.IdLibro
			WHERE IdEjemplar = ?";
		foreach ($compras as $key => $value) {
			$id  = (int)$value['IdEjemplar'];
			$con = (new ConexionBaseDatos)->getConexion();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$id,PDO::PARAM_INT);
			$stmt->execute();
			while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
				$titulos[] = $row['TITULO_LIBRO'];
			}
			$stmt =null;
			$con=null;
		}
		return $titulos;
	}//fin metodo

	public function devolverTiendasLineaVenta(array $compras) :array{
		$tiendas = [];
		include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
		$sql = "SELECT Nombre FROM Tiendas WHERE IdTienda =  ?";
		foreach ($compras as $key => $value) {
			$id  = (int)$value['IdTienda'];
			$con = (new ConexionBaseDatos)->getConexion();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$id,PDO::PARAM_INT);
			$stmt->execute();
			while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
				$tiendas[] = $row['Nombre'];
			}
			$stmt =null;
			$con=null;
		}
		return $tiendas;
	}//fin metodo


	public function confirmarPagoLinea(int $idTienda,int $idVenta,int $idEjemplar, bool $boolPago) :bool{
			$sql ="UPDATE DetalleVenta SET Activo = ? WHERE IdVenta = ? AND IdEjemplar = ? AND IdTienda = ?;";
			$respuesta = false;
			include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
			try{
				$con = (new ConexionBaseDatos)->getConexion();
				$con->beginTransaction();
				$stmt = $con->prepare($sql);
				$stmt->bindParam(1,$boolPago,PDO::PARAM_STR);
				$stmt->bindParam(2,$idVenta,PDO::PARAM_INT);
				$stmt->bindParam(3,$idEjemplar,PDO::PARAM_INT);
				$stmt->bindParam(4,$idTienda,PDO::PARAM_INT);
				if($stmt->execute()){
					$respuesta = true;
				}
				$con->commit();

			}catch(PDOException $ex){
				 throw $ex;
				 $con->rollBack();
			}finally{
				$con = null;
				$stmt = null;
			}
			return $respuesta;
	}//fin metodo

	public function anularLineaPedido(int $idTienda,int $idVenta,int $idEjemplar,bool $boolNulo) :bool{
			$sql ="UPDATE DetalleVenta SET Nulo = ? WHERE IdVenta = ? AND IdEjemplar = ? AND IdTienda = ?;";
			$respuesta = false;
			include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
			try{
				$con = (new ConexionBaseDatos)->getConexion();
				$con->beginTransaction();
				$stmt = $con->prepare($sql);
				$stmt->bindParam(1,$boolNulo,PDO::PARAM_STR);
				$stmt->bindParam(2,$idVenta,PDO::PARAM_INT);
				$stmt->bindParam(3,$idEjemplar,PDO::PARAM_INT);
				$stmt->bindParam(4,$idTienda,PDO::PARAM_INT);
				if($stmt->execute()){
					$respuesta = true;
				}
				$con->commit();

			}catch(PDOException $ex){
				 throw $ex;
				 $con->rollBack();
			}finally{
				$con = null;
				$stmt = null;
			}
			return $respuesta;
	}//fin metodo

	public function devolverCantidadLineaVenta(int $idTienda,int $idVenta,int $idEjemplar) :int{
			$cantidad = 0;
			include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
			$sql = "SELECT Cantidad FROM DetalleVenta WHERE IdVenta = ? AND IdEjemplar = ? AND IdTienda = ?";
			$con = (new ConexionBaseDatos)->getConexion();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$idVenta,PDO::PARAM_INT);
			$stmt->bindParam(2,$idEjemplar,PDO::PARAM_INT);
			$stmt->bindParam(3,$idTienda,PDO::PARAM_INT);
			$stmt->execute();
			while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
				$cantidad = $row['Cantidad'];
			}
			$stmt =null;
			$con=null;
			return $cantidad;
	}//fin metodo

	public function comprobarUsuarioTieneCompras(string $email) :bool{
			$boolCantidad = false;
			include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
			$sql = "SELECT COUNT(DetalleVenta.IdVenta) AS CUENTA from DetalleVenta
							JOIN Venta ON Venta.IdVenta = DetalleVenta.IdVenta
							JOIN Usuario ON Usuario.Usuario = Venta.Usuario
							WHERE Usuario.Email = ?";
			$con = (new ConexionBaseDatos)->getConexion();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$email,PDO::PARAM_STR);

			$stmt->execute();
			while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
					$cantidad = $row['CUENTA'];
					if($cantidad < 1){
							$boolCantidad = false;//no tiene compras
					}else{
							$boolCantidad = true;//tiene compras
					}
			}
			$stmt =null;
			$con=null;
			return $boolCantidad;
	}//fin metodo

	public function devolverNombreTiendaPorIdTiendaVenta(int $idTienda) :string{
				$tienda = '';
				include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
				$sql = "SELECT Nombre FROM Tiendas WHERE IdTienda =  ?";
				$con = (new ConexionBaseDatos)->getConexion();
				$stmt = $con->prepare($sql);
				$stmt->bindParam(1,$idTienda,PDO::PARAM_INT);
				$stmt->execute();
				while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
						$tienda = $row['Nombre'];
				}
				$stmt =null;
				$con=null;
				return $tienda;
	}//fin metodo

}//fin clase
