# Dev Problem Of the Day (08/06/2024)

## Introduction to Web Sockets

- ### What are Web Sockets?

  `Web sockets` are defined as a two-way communication between the servers and the clients, which mean both the parties, communicate and exchange data at the same time.

- ### How are web sockets different from HTTPS?

  `Web Sockets` are different because they work by holding the connection from the client to the server open at all times. This way, the server can send information to the client, even in the absence of an explicit request from the client. The WebSocket connection allows for constant communication in the case of new data being created and therefore needing to be rendered client-side. This is how _Gmail_ emails pop up on your feed instantly, without you have to refresh. We call this **_full-duplex_** communication between the server and the client.

- ### Resources

  - This [link](https://blog.teamtreehouse.com/an-introduction-to-websockets?source=post_page-----10b131182559--------------------------------) gives a brief introduction to everything you need to know about Web Sockets.
  - This [documentation](https://developer.mozilla.org/en-US/docs/Web/API/WebSockets_API) will help in implementing web sockets.
