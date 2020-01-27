<?php ob_start(); include './app/config/nl2br2.php'; ?>
   <h2>Contacta con nosotros</h2>
   <div class="row">
      <div class="col-xs-12 col-md-12 col-lg-12 content_home">
         <p class="contact_exp grey_txt" > No dudes en ponerte en contacto con nosotros para cualquier tipo de duda o aclaración. Responderemos lo antes posible a tu mensaje. </p>
         <p class="contact_exp grey_txt" > No olvides que que debes poner el nombre, el email y el mensaje</p>
      </div>
      <form id="formEnviarMensaje" name="formEnviarMensaje" action="index.php?ctl=enviarMensajeContactoVisitante" method="POST">
         <div class="col-sm-12 col-md-6 col-lg-6">
            <div class="form-group">
               <label for="nombre" class="control-label" data-placement="top">Nombre</label>
               <input type="text" class="form-control" id="nombre" name="nombre" placeholder="Introducir nombre" data-placement="top">
            </div>
         </div>
         <div class="col-sm-12 col-md-6 col-lg-6">
            <label for="email" class="control-label">Email</label>
            <input type="email" class="form-control" id="email" name="email"  placeholder="Introducir email">
         </div>
         <div class="col-sm-12 col-md-12 col-lg-12">
            <label for="mensaje">Mensaje:</label>
            <textarea class="form-control" rows="5" name="mensaje" id="mensaje" placeholder="Escribir mensaje"></textarea>
            <p class="lead centered_item"><button type="submit" id="enviar" class="btn btn-default btn_contacto"><i class="fa fa-envelope-o" aria-hidden="true"></i>  Enviar</button></p>
         </div>
      </form>

   </div>



<?php $contenido = ob_get_clean() ?>
<?php include 'baseInicio.php' ?>
