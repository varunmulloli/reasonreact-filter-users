[@react.component]
let make = (~user: User.user,  ~setModalOpen: bool => unit) => {
  <div style=Styles.container>
    <h5 style=Styles.withMarginBottom>
      {React.string("User Details")}
    </h5>

    <ul className="green-blue-list" style=Styles.withMarginBottom>
      <li className="green-blue-list-item">
        <span className="listing">
          {React.string("Name: ")}
          <strong>{user.name -> Belt.Option.getWithDefault("") -> React.string}</strong>
        </span>
      </li>

      <li className="green-blue-list-item">
        <span className="listing">
          {React.string("Username: ")}
          <strong>{user.username -> Belt.Option.getWithDefault("") -> React.string}</strong>
        </span>
      </li>

      <li className="green-blue-list-item">
        <span className="listing">
          {React.string("Email: ")}
          <strong>{user.email -> Belt.Option.getWithDefault("") -> React.string}</strong>
        </span>
      </li>

      <li className="green-blue-list-item">
        <span className="listing">
          {React.string("Website: ")}
          {
            let website = user.website -> Belt.Option.getWithDefault("");
            <strong><a href=("https://"++website) target="_blank">{React.string(website)}</a></strong>
          }
        </span>
      </li>
    </ul>

    <button onClick={_ => setModalOpen(false)} className="btn-outline btn-md" style=Styles.fullWidth>
      {React.string("Close")}
    </button>
  </div>
};