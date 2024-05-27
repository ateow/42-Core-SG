#!/usr/bin/env python3

def main():
    # Prepare HTML content
    html_content = """
    <html>
    <head>
        <title>Static CGI Page</title>
    </head>
    <body>
        <h1>Welcome to the Static CGI Page</h1>
        <p>This is a static page served through a Python CGI script.</p>
    </body>
    </html>
    """

    # Print HTML content
    print(html_content)

if __name__ == "__main__":
    main()
